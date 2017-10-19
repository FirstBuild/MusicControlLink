# MusicControlLink
nRF24-based system for exchanging music control parameters wirelessly

This project is based on [this tutorial](http://howtomechatronics.com/tutorials/arduino/arduino-wireless-communication-nrf24l01-tutorial/) from Dejan Nedelkovski

There are two parts to this project, a hub, which receives inputs, and control surfaces, 
which send control changes to the hub.  The hub then forwards the information on to other 
units as needed.

No setup is needed for the hub.

### Surface Setup

_Surface Address_

The surface address is set by grounding input pins per the following table.  An X means ground the pin.  A - means do not ground the pin.

Address | D4 | D3 | D2
--------|----|----|---
   0    | -  | -  | -
   1    | -  | -  | X
   2    | -  | X  | -

