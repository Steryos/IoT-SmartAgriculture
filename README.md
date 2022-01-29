# IoT-SmartAgriculture
_Internet of Things Lab Project_

## About this project

This project _aims at creating an IoT unit_, capable of collecting information regarding the humidity and the temperature of both the soil and air.

## Hardware Prerequisites

- Raspberry Pi
- Arduino UNO
- Breadboard
- Serial USB type A to USB type B
- Humidity / Temperature Sensor (DHT11)
- Wires (10cm & 20cm)

Process
^^^^^^^
* We set up a headless Raspberry pi 3 model B v1.2 with the raspberry pi OS Lite
* Using the SSH protocol connected to the pi and installed Docker
* Docker is working.
+
image:https://raw.githubusercontent.com/Steryos/IoT-SmartAgriculture/main/Image1.png[alt="Image1",width=200,height=200]
* Using the Serial USB Cable we connected Pi with the Arduino
* We run lsusb on Pi:

------------
lsusb
------------

* And it's connected to the Arduino
- 
+
image:https://raw.githubusercontent.com/Steryos/IoT-SmartAgriculture/main/Image2.png[alt="Image2",width=200,height=200]


* Running dmesg | grep "tty" on Pi
------------------
dmesg | grep "tty"
------------------

* To figure out where is the Arduino attached to:
* Arduino is atatched to ttytUSB0
+
image:https://raw.githubusercontent.com/Steryos/IoT-SmartAgriculture/main/Image3.png[alt="Image3",width=200,height=200]

* We run the following command to add user Pi to the dialout group
---------------------------
sudo usermod -aG dialout pi
---------------------------

* We then used
----------------
sudo chmod 777 /dev/USB0
----------------
* To give Pi rights for USB0, where it is connected to as mentioned previously
* In order to install the arduino package on pi:
-----------------
sudo apt install arduino-mk
-----------------

* We have to use python in the serial communication between Pi and Arduino so we run:
------------------------------- 
python3 -m pip install pyserial
-------------------------------

* We create a dir named "sketchbook" at:
---------
/home/pi
---------

---------
cd sketchbook
nano Makefile
---------

* Inside sketchbook we create the dir "libraries"
-------
mkdir libraries
-------

* Inside sketchbook we run the following command:
-------
nano sensors.ino
-------
* and we create the file to be uploaded on Arduino
https://raw.githubusercontent.com/Steryos/IoT-SmartAgriculture/main/Image4.png[alt="Image4",width=200,height=200]

* In order to monitor the arduino data in real time we run:
------------
sudo apt install screen
------------