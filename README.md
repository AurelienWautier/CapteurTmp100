# Temperature Sensor Tmp 100 

The purpose of this project is to measure the temparature thanks to a sensor (tmp100) and display the value on a LCD screen

## What will you need 

You will need these followings: 

- ESP8266 
- Digital temperature senson TMP100
- An LCD screen 
- Some cables
- A breadboard

### 1. Hardware setup

Firstly you will need to connect the LCD screen and the temperature sensor in parallel on the i2c bus of the ESP8266.
To do that, use the following pins : 

- D1 : SCL for the clock
- D2 : SDA for data
- G  : GND
- VU : + 5V

### 2. Source Code 

- Install the library : LiquidCristal_i2c for the LCD screen
- Check the adress of your devices in order to communicate in the i2c bus
- Compile the code and flash the ESP8266  







