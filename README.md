Arduino core for Programmable Wireless Stamp (PWS)
===========================================

This project brings support for PWS (ESP8266) to the Arduino environment. It lets you write sketches using familiar Arduino functions and libraries, and run them directly on PWS, no external microcontroller required.

### Installing with Boards Manager ###

Starting with 1.6.5, Arduino allows installation of third-party platform packages using Boards Manager. We have packages available for Windows.

- Install Arduino 1.6.5 from the [Arduino website](http://www.arduino.cc/en/main/software).
- Start Arduino and open Preferences window.
- Enter ```https://raw.githubusercontent.com/QWaveSystems/PWS/master/package/versions/package_qwavesyspws_index.json``` into *Additional Board Manager URLs* field. You can add multiple URLs, separating them with commas.
- Open Boards Manager from Tools > Board menu and install *LabVIEW Arduino* platform (and don't forget to select your Programmable Wireless Stamp (PWS) board from Tools > Board menu after installation).


