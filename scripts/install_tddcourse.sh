#!/bin/bash
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
  echo Google Mock already downloaded.
fi

#echo Install Wordpress
echo Install Wordpress
echo =================
sudo apt-get install --quiet --assume-yes wordpress
sudo ln -s /usr/share/wordpress /var/www/wordpress
sudo apt-get install --quit mysql-server
#MySql root password: tdd1
sudo gzip -d /usr/share/doc/wordpress/examples/setup-mysql.gz
sudo bash /usr/share/doc/wordpress/examples/setup-mysql -n wordpress localhost

#echo Install Jenkins

