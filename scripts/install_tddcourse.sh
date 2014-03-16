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
if [! -f $HOME/google ]; then
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
if [! -f /var/www/wordpress ]; then
  sudo ln -s /usr/share/wordpress /var/www/wordpress
else
  echo WORDPRESS: Symbolic link to /var/www/wordpress already present
fi
sudo apt-get install --quiet --assume-yes mysql-server
#[MANUAL STEP] MySql root password: tdd1
if [! -f /usr/share/doc/wordpress/examples/setup-mysql ]; then
  sudo gzip -d /usr/share/doc/wordpress/examples/setup-mysql.gz
  sudo bash /usr/share/doc/wordpress/examples/setup-mysql -n wordpress localhost
else
  echo WORDPRESS: Wordpress setup script already present
fi
#[MANUAL STEP] Goto: http://localhost/wordpress/wp-admin/install.php
#[MANUAL STEP] Login: tdd1 Password: tdd1 E-mail: jacob.c.mossberg@gmail.com

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
  sudo service apache2 reload
fi
