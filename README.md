This is an arduino code that can be used with any bluetooth capable arduino like ESP32 to act as a remote operated camera shutter with external switches etc.

Prerequisites: https://github.com/T-vK/ESP32-BLE-Keyboard

Credits to https://github.com/T-vK for creating the library that allowed me to even make this.

By default setup for a Normally CLOSED switch to be connected between SWITCH_PIN and GND

I reccommend checking if the pin you chose has a pullup available and if it doesnt interfere with boot if grounded, otherwise its up to you which one you choose

By default setup to send a KEY_MEDIA_VOLUME_UP keyboard press, can be changed easily by replacing with a different key from the above mentioned library

The code prevents sending another keypress untill the switch is released and pressed again

Originally created for 3D printer timelapses as on some printers a simple cable trigger can take multiple photos when printer is purgin and / or the cable can be in the way

Licence: MIT - do whatever you want with it i couldnt care less
