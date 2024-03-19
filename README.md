# IoT-SmartAgriculture
_Internet of Things Lab Project_

## About this project
This project aims at creating an IoT unit, capable of collecting information regarding the humidity and the temperature of both soil and air.

## Hardware Prerequisites
- Raspberry Pi
- Arduino UNO
- Breadboard
- Serial USB type A to USB type B
- Humidity / Temperature Sensor (DHT11)
- Soil Moisture Sensor
- Wires (10cm & 20cm)

## Setup
- We set up a headless Raspberry pi 3 model B v1.2 with the raspberry pi OS Lite
- we SSH into Pi and install Docker

<img src="https://raw.githubusercontent.com/Steryos/IoT-SmartAgriculture/main/Images/Image1.png" alt="Image1" width=750 height=350>

- Using the Serial USB Cable we connected Pi with the Arduino (run lsub to verify)

<img src="https://raw.githubusercontent.com/Steryos/IoT-SmartAgriculture/main/Images/Image2.png" alt="Image2" width=700 height=100>

```
dmesg | grep "tty"
```
- on Pi to figure out where the Arduino is attached to:
- Arduino is attached to ttytUSB0

<img src="https://raw.githubusercontent.com/Steryos/IoT-SmartAgriculture/main/Images/Image3.png" alt="Image3" width=700 height=150>

- Add user pi to the dialout group
```
sudo usermod -aG dialout pi
```
- Give pi rights for USB0
```
sudo chmod 777 /dev/USB0
```
- In order to install the arduino package on pi:
```
sudo apt install arduino-mk
```
- To use python in the serial communication between Pi and Arduino so we run: 
```
python3 -m pip install pyserial
```
- We then create a dir named sketchbook at /home/pi
```
cd sketchbook
vim Makefile
mkdir libraries
```
- We create the .ino file to be uploaded to the Arduino
```
vim sensors.ino
```
<img src="https://raw.githubusercontent.com/Steryos/IoT-SmartAgriculture/main/Images/image4.png" alt="Image43" width=400 height=150>

- In order to monitor the arduino data in real time we run 
```
sudo apt install screen
```