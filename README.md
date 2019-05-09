# Interactive Music Generator
###### Built for Dr. Catherine Chi's MART380 class at the University of South Carolina

# Introduction

[Demonstration](https://youtu.be/Tb5iDYDCC1g)

[Another Demo with clearer Audio](https://www.youtube.com/watch?v=XsCLcTWwn0g)

This is a project I wrote for my New Media Arts class. It involves the use of two Arduinos with one distance sensor each to measure the distance of a user's hand from the sensor. This in turn affects the music being generated in that the chords my change, or the sound may have a large amount of reverb applied. It is a demonstration of Computer Music, MIDI, and the possibilities of Interactive Media.

# System Requirements

Currently I only support linux, but in theory this project can be modified to work on other platforms, such as Windows or MacOS.

Software Required:

- Pure Data (In particular the __i2ork version__, which can be [found here](https://puredata.info/downloads/Pd-L2Ork))

  - The following Packages Must be installed:
  
    - Comport (serial communication module)
    
    - Reverb
    
- Jack Audio Connection Kit (for Linux users to route MIDI and Audio streams through software, [link here](http://jackaudio.org/))

- ZynAddSubFX (Audio Synthesizer, makes the sound for the project. [Download Here](http://zynaddsubfx.sourceforge.net/download.html). Please Download the __Non-ZynFusion__ version.)

- USB 2.0 Connections, or otherwise able to communicate with an arduino through a serial interface.

# Tools Needed

In order to setup this system, you will need:

- 2 Arduinos

- 2 Arduino Ultrasonic Sensors

- Wires and USB cables as appropriate

# Setup Procedure

This is a brief guide to setting up the Arduino software and hardware, as well as Pure Data.

## Arduino

1. Connect the Arduino to the Distance Sensor.

@TODO: Add a Diagram for wiring

__NOTE: Be sure that the ultrasonic sensors point opposite of each other, otherwise interference may occur.__

@TODO: Add Sensor Position Diagram

2. Connect Arduinos to PC

3. Write Program to both Arduinos

## PC

1. Start Jack

  a. Note that QJackCtl has a nice GUI to help with setup if you are into that type of thing
  
2. Start Pure Data

  - Turn on the DSP
  
  - Open up `mart380_final.pd`

3. Start ZynAddSubFX
  
  @TODO Make more detailed instructions

  - Load `inst.xmz`

4. Make connections

  @TODO Talk about connections that need to be made, such as Audio Routing and MIDI

5. In the Opened Pure Data Project, click on the large __Bang__ Object (looks like a button) at the top-left corner of the window, where there is a comment saying "Start".

# Use

By default, the system should be quiet, as the reverb is on full-blast, and the notes are very short. Place hands in front of the sensors, about 20 inches away, and move around, probably closer to the sensor, until the `L` LED on the Arduino illuminates. When this light is lit, you will know that your hand is within the range of the sensor, and a non-zero or 127 value will be sent to the computer.

First, try moving your hands closer to the sensors and listen for the music to get louder. To change Chords, move your hands closely in front of the sensors, until the lights go out (from your hands being too close). After a few ticks, the chord should randomly change.

# Modification

This program can be modified to accomodate different instruments, sensors, or chords. 

@TODO Add details on modifying the Chords and 5 tones.
