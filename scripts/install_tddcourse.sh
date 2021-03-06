#!/bin/bash

TDDCOURSE_REPO=/home/tdd1/repos/tddcourse

echo Installing TDD Course by jacob.c.mossberg@gmail.com
echo Install Eclipse CDT
echo ===================
sudo apt-get install --quiet --assume-yes eclipse-cdt

echo Install gcc
echo ===========
sudo apt-get install --quiet --assume-yes gcc
sudo apt-get install --quiet --assume-yes g++

echo Download Google Test/Google Mock
echo ================================
if [ ! -d $HOME/google ]; then
  mkdir -p $HOME/google
  wget --directory-prefix=$HOME/google -q https://googlemock.googlecode.com/files/gmock-1.7.0.zip
  unzip $HOME/google/gmock-1.7.0.zip -d $HOME/google
  rm -f $HOME/google/gmock-1.7.0.zip
else
  echo GOOGLE MOCK: Google Mock already downloaded.
fi

echo Install Wordpress
echo =================
sudo apt-get install --quiet --assume-yes wordpress
if [ ! -e /var/www/wordpress ]; then
  sudo ln -s /usr/share/wordpress /var/www/wordpress
else
  echo WORDPRESS: Symbolic link to /var/www/wordpress already present
fi
sudo apt-get install --quiet --assume-yes mysql-server
#[MANUAL STEP] MySql root password: tdd1
if [ ! -f /usr/share/doc/wordpress/examples/setup-mysql ]; then
  sudo gzip -d /usr/share/doc/wordpress/examples/setup-mysql.gz
  sudo bash /usr/share/doc/wordpress/examples/setup-mysql -n wordpress localhost
else
  echo WORDPRESS: Wordpress setup script already present
fi
#[MANUAL STEP] Goto: http://localhost/wordpress/wp-admin/install.php
#[MANUAL STEP] Login: tdd1 Password: tdd1 E-mail: jacob.c.mossberg@gmail.com

echo Setup FTP access to Wordpress site
sudo apt-get install vsftpd

echo Install Jenkins
echo ===============
sudo apt-get install --quiet --assume-yes jenkins
sudo apt-get install --quiet --assume-yes libapache2-mod-proxy-html
ORIGINAL_APACHE_SITE=/etc/apache2/sites-available/000-default.conf
TDDCOURSE_APACHE_SITE=$TDDCOURSE_REPO/apache2/default
if (cmp $ORIGINAL_APACHE_SITE $TDDCOURSE_APACHE_SITE); then 
  echo JENKINS: Apache2 site configuration already setup for Jenkins proxy
else
  sudo cp /etc/apache2/sites-available/000-default.conf /etc/apache2/sites-available/000-default_original.conf
  sudo rm -f /etc/apache2/sites-availabe/000-default.conf
  sudo cp $TDDCOURSE_REPO/apache2/default /etc/apache2/sites-available/000-default.conf
fi

JENKINS_CONF_FILE=/etc/default/jenkins
if (grep -q "prefix=/jenkins" $JENKINS_CONF_FILE); then
  echo JENKINS: Jenkins configuration file already contains prefix to /jenkins
else
  echo 'JENKINS_ARGS="$JENKINS_ARGS --prefix=/jenkins"' | sudo tee -a $JENKINS_CONF_FILE > /dev/null
fi
sudo service jenkins restart
sudo a2enmod proxy
sudo a2enmod proxy_html
sudo a2enmod proxy_http
sudo a2enmod xml2enc
sudo a2dissite 000-default
sudo service apache2 restart
sudo a2ensite 000-default
sudo service apache2 restart

echo Setup WordsrepAppReference project workspace for Eclipse CDT
echo ============================================================
LOCAL_REFERENCE_PROJECT_LOCATION=$HOME/eclipse_cdt_workspaces/reference/
REPO_REFERENCE_PROJECT=$TDDCOURSE_REPO/reference/WordsrepAppReference
if [ ! -d $LOCAL_REFERENCE_PROJECT_LOCATION ]; then
  mkdir -p $LOCAL_REFERENCE_PROJECT_LOCATION
  cp -r $REPO_REFERENCE_PROJECT $LOCAL_REFERENCE_PROJECT_LOCATION
  eclipse -nosplash -application org.eclipse.cdt.managedbuilder.core.headlessbuild -data $LOCAL_REFERENCE_PROJECT_LOCATION -importAll $LOCAL_REFERENCE_PROJECT_LOCATION
else
  echo Eclipse CDT reference project already setup.
fi

