#!/bin/bash
echo Installing TDD Course by jacob.c.mossberg@gmail.com
echo Install Eclipse
echo ===============
sudo apt-get install --quiet --assume-yes eclipse-cdt

echo Install gcc
echo ===========
sudo apt-get install --quiet --assume-yes gcc
sudo apt-get install --quiet --assume-yes g++

echo Download Google Test/Google Mock
echo ================================
mkdir ~/google
wget https://googlemock.googlecode.com/files/gmock-1.7.0.zip
cd ~/google
unzip ~/google/gmock-1.7.0.zip -d ~/google
rm -f ~/google/gmock-1.7.0.zip

#echo Install Apache2
#echo Install Jenkins
#echo Install Wordpress

