#include "Arduino.h" // required for added .h file inclusion
#include "config.h"  // pins, constants definitions

//**********************************************************************
// External digital blink using state machine.

volatile boolean isSample = false;
boolean isPulseActive = false; // isDisplayEn = false;
unsigned int pulseTick, pTicksA = 7, pTicksB = 3;
float pulseVal = 0.0;

//**********************************************************************
void setup()
{
  initArduinoEnvironment();
  initTimer();  
  Serial.println(F("Controls 427: state machine digital pulse"));  
  showHelpMenu();
}

//**********************************************************************
void loop()
{
  syncSampleTime();
  manageMenu();
  
  pulseDigitalLED();
    
} // loop()

//**********************************************************************
void syncSampleTime(void)
{
  while (!isSample);  // spin until next sample time from ISR 
  isSample = false;   // lock out until next sample interval start
}
 
//**********************************************************************
void initArduinoEnvironment(void)
{ 
  pinMode(RLED, OUTPUT); digitalWrite(RLED,LOW);
  pinMode(UC_LED, OUTPUT); digitalWrite(UC_LED,LOW);

  Serial.begin(115200);
  while (!Serial); // await comm open
  Serial.println(F("Set console line ending option to 'Carriage return'."));
  delay(10); // complete output to console before leaving
}
