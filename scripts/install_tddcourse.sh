#!/bin/bash
echo Installing TDD Course by jacob.c.mossberg@gmail.com
echo Install Eclipse
echo ===============
sudo apt-get install eclipse

echo Download Google Test/Google Mock
echo ================================
mkdir ~/google
wget https://googlemock.googlecode.com/files/gmock-1.7.0.zip
cd ~/google
unzip gmock-1.7.0.zip
rm -f gmock-1.7.0.zip

#echo Install Apache2
#echo Install Jenkins
#echo Install Wordpress

