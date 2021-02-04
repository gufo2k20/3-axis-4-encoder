# 3-axis-4-encoder
3 axis 4 encoder button box HID

simple ButtonBox for PC
tested with Arduino Pro Micro (HID)

BOM
1x Arduino Pro Micro (tested 5V16Mhz)
3x linear potentiometer 10k
4x rotary encoders with pushbutton
1x OLED 128x64 display for input page info

nedd following libraries:
ClickEncoder.h
TimerOne.h
Joystick.h
Wire.h
Adafruit_GFX.h
Adafruit_SSD1306.h

Features:
- 3 axis (X, Y, Z)
- 48 buttons
- each encoder correspond to 3 buttons (clockwise, anti-clockwise and click)
- double-clicking an ancoder switch to related "state-page" (eg. page 3 = buttons from 24 to 35)
- OLED display report the currently active "State page"

NOTES.
- pinout can be easily retrieved in code (3 analog, 12 digital +2 for I2C
- VERY EARLY REALEASE CODE
- This is my first Arduino project. Any help is welcome for some array anf for loop implementation....

MANY THANKS TO ALL AUTHORS OF THE LIBRARIES!
