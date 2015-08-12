Xadow Edison OLED Widget
===========================

[* Xadow Edison OLED Widget *](http://www.seeedstudio.com/depot/Xadow-RGB-OLED-96x64-p-2125.html))

This code was forked from the SparkFun Edison OLED block and is intended to get the Xadow OLED going on Ubilinux.

The SKU at SeeedStudio for this block at the time it was purchased was 104040001.

Status:
Initial port to the Xadow RGB LED device.  This also chnages the "pong" game to
be a clock with a QR code that represents the time.  The changes to the init code
(ie the port from the 1306 to the 1331) came from Arduino code here:
        https://github.com/Seeed-Studio/RGB_OLED_SSD1331

Unfortunately, not everything is done here yet but this should get you started.
Comments haven't always been modified to match the code.



Repository Contents
-------------------
* **/Firmware** - Example Arduino Sketch
* **/Hardware** - All Eagle design files (.brd, .sch)
* **/Production** - Test bed files and production panel files

License Information
--------------------

The SparkFun hardware is released under [Creative Commons ShareAlike 4.0 International](https://creativecommons.org/licenses/by-sa/4.0/).
The code is beerware; if you see me (or any SparkFun employee) at the local, and you've found our code helpful, please buy us a round!

Distributed as-is; no warranty is given.
