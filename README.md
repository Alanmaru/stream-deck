# DIY USB Stream Deck

A custom USB macro pad built with an Arduino Leonardo and HID controls.

## Overview

This project is a custom-built USB macro pad inspired by the concept of a Stream Deck.

The device uses an Arduino Leonardo to emulate a keyboard and media controller through USB. It currently features four physical buttons for window switching and music control, along with a rotary encoder for volume control and mute.

The enclosure and future hardware improvements will be 3D printed and designed specifically for this project.

## Features

- USB HID keyboard controls
- Media controls
- Window switching with `Alt + Tab`
- Previous, play/pause and next track controls
- Rotary encoder for volume control
- Encoder push button for mute
- Tactile button input
- Expandable design for future buttons and controls

## Hardware

- Arduino Leonardo
- 4 tactile buttons
- Rotary encoder with push button
- Breadboard
- Dupont jumper wires
- Brown mechanical switch (prototype test)

## Software

- Arduino IDE
- C/C++
- HID-Project library

## Current Button Mapping

| Button | Function |
|--------|----------|
| BT1 | Next track |
| BT2 | Alt + Tab |
| BT3 | Play / Pause |
| BT4 | Previous track |

## Rotary Encoder

| Control | Function |
|---------|----------|
| Rotate clockwise | Volume up |
| Rotate counterclockwise | Volume down |
| Press | Mute / Unmute |

## Hardware Testing

### Mechanical Switch Prototype

A brown mechanical switch was connected to the Arduino Leonardo prototype using Dupont wires.

The switch worked correctly and was able to trigger the assigned function.

This test was performed to verify that mechanical switches could be used as the physical inputs for the final version of the Stream Deck.

### Rotary Encoder Prototype

A rotary encoder with an integrated push button was connected to the Arduino Leonardo prototype.

The encoder was successfully tested for rotational input and button presses.

The encoder is currently used for volume control and mute functionality.

## Project Status

Currently working prototype.

Completed:

- USB HID keyboard controls
- Media controls
- Window switching
- Rotary encoder volume control
- Encoder mute button
- Mechanical switch prototype test

Future improvements may include:

- Mechanical switches for the final version
- Custom 3D-printed enclosure
- Improved wiring and assembly
- Additional HID functions
- Additional buttons and controls