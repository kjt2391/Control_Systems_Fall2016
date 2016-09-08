  #include "Arduino.h" // required for added .h file inclusion
#include "config.h"  // pins, constants definitions

//**********************************************************************
// Apparent 'analog' output using PWM of timer controlled digital pin

#define RLED 11
#define YLED 13

//**********************************************************************
void setup()
{
  initArduinoEnvironment();
  initTimer();

} // setup()

//**********************************************************************
void loop()
{
  OCR2A = 50;
  delay(1000);
  OCR2A = 100;
  delay(500);
  OCR2A = 200;
  delay(500);
  OCR2A = 400;
  delay(500);
  OCR2A = 511;
  delay(500);
   
} // loop()

//**********************************************************************
void initArduinoEnvironment(void)
{ 
  pinMode(RLED, OUTPUT); digitalWrite(RLED,HIGH);
  pinMode(YLED, OUTPUT); digitalWrite(YLED,LOW);
}
