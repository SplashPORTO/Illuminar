# Illuminar
Light Sensor Control


# About
Sometimes you need a light switch on places you dont want it to be visible or places where you can't touch with your hands.
Thats why we developed this proyject to control a light, or any other device, with gestures, a small Ir sensor connected to an Arduino chip.

# Details
This project consists on 2 separated electronic elemenst connected to one arduino
### IR sensor
For the gesture reading we use 2 IR LEDs and 1 IR phototransistor, when you hover the hand over the sensor, the light gets reflected from your hand and meassured by the phototransistor, more light gets reflected the nearer the sensor your hand is.

### Light regulation
For regulating light (on/of and Brightnes) we use a 12V prover supply connected to a N-channel mosfet using the PWM output for the arduino as a switching power regulator.


# How to use it
swipe over the sensor with your hand to turn on/off the light.
To dim the light; hold your hand over the sensor and after 1/2 Second, the system will enter dim mode. then you can cahnge the distance to the sensor to dim the light; to store the disired vlaue, just swipe out of the sensor area.

# Authors
Andres Bott.

Nuno Soares
