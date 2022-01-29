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

## Process
* We set up a headless Raspberry pi 3 model B v1.2 with the raspberry pi OS Lite
* Using the SSH protocol we connected to pi and installed Docker
- Docker is working.
+
image:https://raw.githubusercontent.com/Steryos/IoT-SmartAgriculture/main/Image1.png[alt="Image1",width=600,height=350]
* Using the Serial USB Cable we connected Pi with the Arduino
* `lsusb` on Pi

- And it's connected to the Arduino
+
image:https://raw.githubusercontent.com/Steryos/IoT-SmartAgriculture/main/Image2.png[alt="Image2",width=700,height=150]


* `dmesg | grep "tty"` on Pi to figure out where is the Arduino attached to:
- Arduino is attached to ttytUSB0
+
image:https://raw.githubusercontent.com/Steryos/IoT-SmartAgriculture/main/Image3.png[alt="Image3",width=700,height=150]

* `sudo usermod -aG dialout pi` to add user Pi to the dialout group
* `sudo chmod 777 /dev/USB0` To give Pi rights for USB0, where it is connected to as mentioned previously
 
* `sudo apt install arduino-mk` In order to install the arduino package on pi:

* `python3 -m pip install pyserial` to use python in the serial communication between Pi and Arduino so we run:


* We then create a dir named _sketchbook_ at -> */home/pi*

* Inside _sketchbook_

- `nano Makefile`

- `mkdir libraries`

* Then we run the following command `nano sensors.ino`
- and we create the file to be uploaded on Arduino

+
image:https://raw.githubusercontent.com/Steryos/IoT-SmartAgriculture/main/image4.png[alt="image4",width=700,height=150]


* In order to monitor the arduino data in real time we run `sudo apt install screen`
