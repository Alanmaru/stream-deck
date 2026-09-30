# DIY USB Stream Deck

A custom USB macro pad built with an Arduino Leonardo and HID controls.

## Overview

This project is a custom-built USB macro pad inspired by the concept of a Stream Deck.

The device uses an Arduino Leonardo to emulate a keyboard and media controller through USB. It currently features four physical buttons for window switching and music control.

The enclosure and future hardware improvements will be 3D printed and designed specifically for this project.

## Features

- USB HID keyboard controls
- Media controls
- Window switching with `Alt + Tab`
- Previous, play/pause and next track controls
- Analog volume control
- Mechanical button input
- Custom 3D-printed enclosure planned
- Expandable design for future buttons and controls

## Hardware

- Arduino Leonardo
- 4 tactile buttons
- Breadboard
- Dupont jumper wires
- Potentiometer
- Brown mechanical switch (prototype test)
- 3D-printed parts (planned)

## Software

- Arduino IDE
- C/C++
- HID-Project library

## Current Button Mapping

| Button | Function |
|--------|----------|
| BT1 | Alt + Tab |
| BT2 | Previous track |
| BT3 | Play / Pause |
| BT4 | Next track |

## Hardware Testing

### Mechanical Switch Prototype

A brown mechanical switch was connected to the Arduino Leonardo prototype using Dupont wires.

The switch worked correctly and was able to trigger the assigned function.

This test was performed to verify that mechanical switches could be used as the physical inputs for the final version of the Stream Deck.

The final version will use mechanical switches and a custom 3D-printed enclosure.

## Project Status

Currently working prototype.

Completed:

- USB HID keyboard controls
- Media controls
- Window switching
- Analog volume control
- Mechanical switch prototype test

Future improvements may include:

- Additional buttons
- Custom 3D-printed enclosure
- Mechanical switches
- Improved wiring and assembly
- Additional HID functions