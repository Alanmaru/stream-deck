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
- Mechanical button input
- Custom 3D-printed enclosure planned
- Expandable design for future buttons and controls

## Hardware

- Arduino Leonardo
- 4 tactile buttons
- Breadboard
- Dupont jumper wires
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

## Project Status

Currently working prototype.

Future improvements may include:

- Analog volume control
- Additional buttons
- Custom 3D-printed enclosure
- Mechanical switches
- Improved wiring and assembly
- Additional HID functions