//**********************************************************************
//**********************************************************************
//                                 MENU CODE
//**********************************************************************
//**********************************************************************

void showHelpMenu(void)
{
  Serial.println(F("\nEnter h for help."));
  Serial.println(F("Enter p to set pulse parms."));
}

//**********************************************************************
void showPulseMenu(void)
{
  Serial.println(F("\nTo change value xy to aa.bb, enter xyaa.bb"));
  Serial.println(F("Enter 'ux.x' for step to level x.x (float)."));
  Serial.println(F("------------------------------------------"));
  Serial.println(F("Pulse run: p"));
  Serial.print(F("Pulse ticks A: pa ("));
  Serial.print(pTicksA); Serial.println(")");
  Serial.print(F("Pulse ticks B: pb ("));
  Serial.print(pTicksB); Serial.println(")"); 
}

//**********************************************************************
void manageMenu(void)
{
  const char CR = '\r'; // ascii carriage return
  static String strBuff = "";
  char chIn;

  if (Serial.available())
  {
    chIn = Serial.read();
    if (chIn != CR) strBuff += chIn;
  }
  
  if (chIn == CR)
  {
    if (strBuff.startsWith("h")) 
    {
       showHelpMenu();
    }

    //------------------------------------------------------------------
    // Pulse specification

    else if (strBuff.startsWith("p"))
    {     
      if (strBuff.startsWith("pa"))
      {
        if (strBuff.length() > 2) {
          pTicksA = strBuff.substring(2).toInt();
        }
      }
      else if (strBuff.startsWith("pb"))
      {
        if (strBuff.length() > 2) {
          pTicksB = strBuff.substring(2).toInt();
        }
      }
      if (strBuff.length() < 2)
      { 
        isPulseActive = true; // trigger pulse generator 
      }
     
      showPulseMenu();

    } // else if (strBuff.startsWith("u"))

    //------------------------------------------------------------------
    // Unrecognized user input
    
    else
    {
      Serial.println(F("Unrecognized input."));
    }    
    strBuff = "";
    
  } // if (chIn == CR)

} // void manageMenu(void)

