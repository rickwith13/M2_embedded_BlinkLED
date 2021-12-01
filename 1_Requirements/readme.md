# Employee Management System 

# Requirements

## Introduction 
- Ultrasonic Module HC-SR04 works on the principle of SONAR and RADAR system.
HC-SR-04 module has an ultrasonic transmitter, receiver, and control circuit on a single board.
- The module has only 4 pins, Vcc, Gnd, Trig, and Echo.
- When a pulse of 10µsec or more is given to the Trig pin, 8 pulses of 40 kHz are generated. After this, the Echo pin is made high by the control circuit in the module.
- The echo pin remains high till it gets an echo signal of the transmitted pulses back.
- The time for which the echo pin remains high, i.e. the width of the Echo pin gives the time taken for generated ultrasonic sound to travel towards the object and return.
- Using this time and the speed of sound in air, we can find the distance of the object using a simple formula for distance using speed and time.
 ## Scope
 Ultrasonic sensor
================

Introduction
------------
Interfacing an ultrasonic sensor to measure the distance to objects in(cm) and displaying the distance on 2x16 LCD using ATmega32 with the AVR toolchain.

Hardware
--------
* AVR ATmega32 microcontroller.
* Uspasp programmer
* Ultrasonic sensor (HC-SR04)
* 2x16 LCD

Distance Calculation
--------
Sound velocity =   343.00 m/s = 34300 cm/s

Distance of Object (in cm)
                        = (Sound velocity * TIMER Value) / 2

                        = (34300 * TIMER Value) / 2

                        = 17150  * Timer Value

we have selected internal 8 MHz oscillator frequency for ATmega32, with No-presale for timer frequency. Then time to execute 1 instruction is 0.125 us
So, timer gets incremented after 0.125 us time elapse.

                 = 17150 x (TIMER value) x 0.125 x 10^-6 cm

                 = 0.125 x (TIMER value)/58.30 cm

                 = (TIMER value) / 466.47 cm

Circuit
--------
![ultrasonic](circuit/ultrasonic.PNG)

Installation
------------
You will need to have the AVR toolchain installed on your system. This includes:
* avr-gcc
* avr-libc
* avrdude
  | 

   


