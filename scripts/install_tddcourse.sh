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
mkdir -p $HOME/google
wget --directory-prefix=$HOME/google -q https://googlemock.googlecode.com/files/gmock-1.7.0.zip
unzip $HOME/google/gmock-1.7.0.zip -d $HOME/google
rm -f $HOME/google/gmock-1.7.0.zip

#echo Install Apache2

sudo 
#echo Install Jenkins
#echo Install Wordpress

