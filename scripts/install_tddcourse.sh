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
mkdir -p ~/google
wget --directory-prefix=~/google -q https://googlemock.googlecode.com/files/gmock-1.7.0.zip
unzip ~/google/gmock-1.7.0.zip -d ~/google
rm -f ~/google/gmock-1.7.0.zip

#echo Install Apache2
#echo Install Jenkins
#echo Install Wordpress

