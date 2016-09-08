#include "Arduino.h" // required for added .h file inclusion
#include "config.h"  // pins, constants definitions

//**********************************************************************
const unsigned int R_MAX_TICKS = 5;
const unsigned int Y_MAX_TICKS = 10;

volatile boolean isSample = false;
boolean isRedPulse = false, isMicroPulse = false;
char chIn = ' ';

//**********************************************************************
void setup()
{
  initArduinoEnvironment();
  initTimer();
  
  Serial.println(F("HW2 Controls 427: time base pulse states"));  
  Serial.println("\nEnter 'r' for red LED pulse.");
  Serial.println("Enter 'b' for uC board LED pulse.\n");
}

//**********************************************************************
void loop()
{
  syncSampleTime();
  
  if (Serial.available()) chIn = Serial.read();
  if(chIn == 'r') isRedPulse = true;
  if(chIn == 'b') isMicroPulse = true;
 
  pulseRedSM();
  pulseMicroSM();
    
} // loop()

//**********************************************************************
void syncSampleTime(void)
{
  while (!isSample);      // spin until next sample time from ISR 
  isSample = false;       // lock out until next sample interval start
}

//**********************************************************************
void initArduinoEnvironment(void)
{ 
  pinMode(RLED, OUTPUT); digitalWrite(RLED,LOW);
  pinMode(UC_LED, OUTPUT); digitalWrite(UC_LED,LOW);

  Serial.begin(115200);
  while (!Serial); // await comm link
  Serial.println(F("Set console line ending option to 'Carriage return'."));
  delay(10); // complete output to console before leaving
}
//blah blah blah
