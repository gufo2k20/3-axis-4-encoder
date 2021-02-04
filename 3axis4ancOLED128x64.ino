#include <ClickEncoder.h>
#include <TimerOne.h>
#include <Joystick.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define NUM_ANALOG  3 // the number of analog inputs

int analog_value[NUM_ANALOG];
byte analog_pin[NUM_ANALOG] = {A0,A1,A2}; // analog input pins X,Y,Z
    
Joystick_ Joystick(
  JOYSTICK_DEFAULT_REPORT_ID,
  JOYSTICK_TYPE_JOYSTICK,
  48, // total buttons, each "page" has 3 buttons for each rotary encoder (Sx,Dx,PUSHBTN)
  0,
  true,  // includeXAxis       1
  true,  // includeYAxis       2
  true,  // includeZAxis       3
  false,  // includeRxAxis      4
  false,  // includeRyAxis      5
  false,  // includeRzAxis      6
  false,  // includeRudder      7
  false,  // includeThrottle    8
  false,  // includeAccelerator
  false,  // includeBrake
  false); // includeSteering
       
ClickEncoder *encoder1, *encoder2, *encoder3, *encoder4;

int     page = 1;
int     encdir1, encdir2, encdir3, encdir4;
int16_t last1, value1, last2, value2, last3, value3, last4, value4;

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire, 4);

void timerIsr() {
  encoder1->service();
  encoder2->service();
  encoder3->service();
  encoder4->service();
  }

void setup() {

  encoder1 = new ClickEncoder(0, 1, 10);
  encoder2 = new ClickEncoder(4, 5, 14);
  encoder3 = new ClickEncoder(6, 7, 15);
  encoder4 = new ClickEncoder(8, 9, 16);
     
  Timer1.initialize(1000);
  Timer1.attachInterrupt(timerIsr);
     
  last1 = -1;
  last2 = -1;
  last3 = -1;
  last4 = -1;

  Joystick.begin(false); 
    Joystick.setXAxisRange   (0,1023);
    Joystick.setYAxisRange   (0,1023);
    Joystick.setZAxisRange   (0,1023);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3c);
  display.display();
  delay(2000);

  display.clearDisplay();
  display.display();

  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(15,20);
  display.print("Cpt.Gufo");
  display.setCursor(32,47);
  display.print("Panel");
  display.display();
  
  delay(2000);
  display.clearDisplay();
  display.display();

  display.setTextSize(6);
  display.setCursor(48,20);
  display.print(page);
  display.display();
  }

void loop() {

  value1 += encoder1->getValue();
  value2 += encoder2->getValue();
  value3 += encoder3->getValue();
  value4 += encoder4->getValue();

// encoder1 rotation check and action
  if (value1 == last1) Joystick.releaseButton(0),
                       Joystick.releaseButton(1),
                       Joystick.releaseButton(12),
                       Joystick.releaseButton(13),
                       Joystick.releaseButton(24),
                       Joystick.releaseButton(25),
                       Joystick.releaseButton(36),
                       Joystick.releaseButton(37);
    else {
      if (value1 < last1) encdir1 = 0; else encdir1 = 1;
        switch (page)
        {          
          case 1:
            if (encdir1 == 0) Joystick.pressButton(0);
            else Joystick.pressButton(1);
            break;
          case 2:
            if (encdir1 == 0) Joystick.pressButton(12);
            else Joystick.pressButton(13);
            break;
          case 3:
            if (encdir1 == 0) Joystick.pressButton(24);
            else Joystick.pressButton(25);
            break;
          case 4:
            if (encdir1 == 0) Joystick.pressButton(36);
            else Joystick.pressButton(37);
            break;          
          } 
    }
    last1 = value1;

// encoder2 rotation check and action
  if (value2 == last2) Joystick.releaseButton(3),
                       Joystick.releaseButton(4),
                       Joystick.releaseButton(15),
                       Joystick.releaseButton(16),
                       Joystick.releaseButton(27),
                       Joystick.releaseButton(28),
                       Joystick.releaseButton(39),
                       Joystick.releaseButton(40);
    else {
      if (value2 < last2) encdir2 = 0; else encdir2 = 1;
        switch (page)
        {          
          case 1:
            if (encdir2 == 0) Joystick.pressButton(3);
            else Joystick.pressButton(4);
            break;
          case 2:
            if (encdir2 == 0) Joystick.pressButton(15);
            else Joystick.pressButton(16);
            break;
          case 3:
            if (encdir2 == 0) Joystick.pressButton(27);
            else Joystick.pressButton(28);
            break;
          case 4:
            if (encdir2 == 0) Joystick.pressButton(39);
            else Joystick.pressButton(40);
            break;          
          } 
    }
    last2 = value2;

// encoder3 rotation check and action
  if (value3 == last3) Joystick.releaseButton(6),
                       Joystick.releaseButton(7),
                       Joystick.releaseButton(18),
                       Joystick.releaseButton(19),
                       Joystick.releaseButton(30),
                       Joystick.releaseButton(31),
                       Joystick.releaseButton(42),
                       Joystick.releaseButton(43);
    else {
      if (value3 < last3) encdir3 = 0; else encdir3 = 1;
        switch (page)
        {          
          case 1:
            if (encdir3 == 0) Joystick.pressButton(6);
            else Joystick.pressButton(7);
            break;
          case 2:
            if (encdir3 == 0) Joystick.pressButton(18);
            else Joystick.pressButton(19);
            break;
          case 3:
            if (encdir3 == 0) Joystick.pressButton(30);
            else Joystick.pressButton(31);
            break;
          case 4:
            if (encdir3 == 0) Joystick.pressButton(42);
            else Joystick.pressButton(43);
            break;          
          }
    }
    last3 = value3;

// encoder4 rotation check and action
  if (value4 == last4) Joystick.releaseButton(9),
                       Joystick.releaseButton(10),
                       Joystick.releaseButton(21),
                       Joystick.releaseButton(22),
                       Joystick.releaseButton(33),
                       Joystick.releaseButton(34),
                       Joystick.releaseButton(45),
                       Joystick.releaseButton(46);
    else {
      if (value4 < last4) encdir4 = 0; else encdir4 = 1;
        switch (page)
        {          
          case 1:
            if (encdir4 == 0) Joystick.pressButton(9);
            else Joystick.pressButton(10);
            break;
          case 2:
            if (encdir4 == 0) Joystick.pressButton(21);
            else Joystick.pressButton(22);
            break;
          case 3:
            if (encdir4 == 0) Joystick.pressButton(33);
            else Joystick.pressButton(34);
            break;
          case 4:
            if (encdir4 == 0) Joystick.pressButton(45);
            else Joystick.pressButton(46);
            break;          
          } 
    }
    last4 = value4;
                    
// encoder1 click check and action (single, double-clicked)
    ClickEncoder::Button a = encoder1->getButton();
      if (a != ClickEncoder::Open) {        
        switch (a)
        {          
          case ClickEncoder::DoubleClicked:
            page = 1;
            display.clearDisplay();
            display.display();
            display.setCursor(48,20);
            display.print(page);
            display.display();
            break;
          case ClickEncoder::Clicked:
              switch (page) {
                case 1:
                Joystick.pressButton(2);
               break;
                case 2:
                Joystick.pressButton(14);
               break;
                case 3:
                Joystick.pressButton(26);
               break;
                case 4:
                Joystick.pressButton(38);
              break;
              }
          } 
        } else Joystick.releaseButton(2), Joystick.releaseButton(14), Joystick.releaseButton(26), Joystick.releaseButton(38);

// encoder2 click check and action (single, double-clicked)
      ClickEncoder::Button b = encoder2->getButton();
      if (b != ClickEncoder::Open)
      {
        switch (b)
        {
          case ClickEncoder::DoubleClicked:
            page = 2;
            display.clearDisplay();
            display.display();
            display.setCursor(48,20);
            display.print(page);
            display.display();
            break;
          case ClickEncoder::Clicked:
              switch (page) {
                case 1:
                Joystick.pressButton(5);
               break;
                case 2:
                Joystick.pressButton(17);
               break;
                case 3:
                Joystick.pressButton(29);
               break;
                case 4:
                Joystick.pressButton(41);
              break;
              }
        }
      } else Joystick.releaseButton(5), Joystick.releaseButton(17), Joystick.releaseButton(29), Joystick.releaseButton(41);

// encoder3 click check and action (single, double-clicked)
      ClickEncoder::Button c = encoder3->getButton();
      if (c != ClickEncoder::Open)
      {
        switch (c)
        {
          case ClickEncoder::DoubleClicked:
            page = 3;
            display.clearDisplay();
            display.display();
            display.setCursor(48,20);
            display.print(page);
            display.display();
            break;
          case ClickEncoder::Clicked:
              switch (page) {
                case 1:
                Joystick.pressButton(8);
               break;
                case 2:
                Joystick.pressButton(20);
               break;
                case 3:
                Joystick.pressButton(32);
               break;
                case 4:
                Joystick.pressButton(44);
              break;
              }
        }
      } else Joystick.releaseButton(8), Joystick.releaseButton(20), Joystick.releaseButton(32), Joystick.releaseButton(44);

// encoder4 click check and action (single, double-clicked)
      ClickEncoder::Button d = encoder4->getButton();
      if (d != ClickEncoder::Open)
      {
        switch (d)
        {
          case ClickEncoder::DoubleClicked:
            page = 4;
            display.clearDisplay();
            display.display();
            display.setCursor(48,20);
            display.print(page);
            display.display();
            break;
          case ClickEncoder::Clicked:
              switch (page) {
                case 1:
                Joystick.pressButton(11);
               break;
                case 2:
                Joystick.pressButton(23);
               break;
                case 3:
                Joystick.pressButton(35);
               break;
                case 4:
                Joystick.pressButton(47);
              break;
              }
        }
      } else Joystick.releaseButton(11), Joystick.releaseButton(23), Joystick.releaseButton(35), Joystick.releaseButton(47);

// axis X Y Z check
        for (byte i=0; i<NUM_ANALOG; i++) { // read analog inputs
          analog_value[i] = analogRead(analog_pin[i]);
          switch(i) {
            case 0:
              Joystick.setXAxis(1023 - analog_value[0]);
            break;
            case 1:
               Joystick.setYAxis(1023 - analog_value[1]);
            break;
            case 2:
               Joystick.setZAxis(1023 - analog_value[2]);
            break;
            }
          }

delay (50);
Joystick.sendState();

}
