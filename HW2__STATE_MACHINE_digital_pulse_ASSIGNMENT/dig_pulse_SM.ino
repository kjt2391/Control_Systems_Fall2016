//**********************************************************************
void pulseDigitalLED(void)
{
  const boolean IS_VERBOSE = true;  
  enum {PULSE, DWELL, DONE};
  static byte state = DONE, prevState = DONE;
  static unsigned int runTicks; // state transition tick target
  boolean isNewState;

  isNewState = (state != prevState);
  prevState = state;
  switch (state)
  {
    //----------------------------------------------
    case PULSE:
      // entry behavior
      if (isNewState)
      {
        if (IS_VERBOSE) Serial.println("PULSE");
        pulseTick = 0;
        runTicks = pTicksA;
        digitalWrite(RLED,RLED_ON);
        Serial.println("tick");
      }
      
      // state business
      pulseTick++;
      Serial.println(pulseTick);

      // exit condition
      if (pulseTick >= runTicks) state = DWELL;

      break;

    //----------------------------------------------
    case DWELL:
      // entry behavior
      if (isNewState)
      {
        if (IS_VERBOSE) Serial.println("DWELL");
        runTicks += pTicksB;
        digitalWrite(RLED,RLED_OFF);
        digitalWrite(UC_LED,UC_LED_ON);      
      }
      
      // state business
      pulseTick++;
      Serial.println(pulseTick);

      // exit condition
      if (pulseTick >= runTicks) state = DONE;

      break;
 
    //----------------------------------------------
    case DONE:
      // entry behavior
      if (isNewState)
      {
        if (IS_VERBOSE) Serial.println("DONE");
        isPulseActive = false;
        digitalWrite(UC_LED,UC_LED_OFF);
      }

      // state business: none
      
      // exit condition
      if (isPulseActive) state = PULSE;  
   
      break;
 
    //----------------------------------------------    
    default: state = DONE;
  
  } // switch (state)
  
} // void pulse1()
