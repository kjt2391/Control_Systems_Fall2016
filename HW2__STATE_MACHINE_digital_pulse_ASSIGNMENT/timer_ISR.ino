//**********************************************************************
//**********************************************************************
//                            TIMER CODE
//**********************************************************************
//**********************************************************************

void initTimer(void)
{
  cli(); // disable global interrupts 

  //--------------------------------------------------------------------
  // Use Timer 1 (16 bit) for pulse generation.
  // Prescale 16 MHz by 8 for 0.5 usec resolution and 32.768 msec range.
  // FAST PWM mode with ICR1 defined cycle length (TOP value), (Mode 14)
  // Decouple Timer 3 counter from output pins.
  // Set PWM period for 10 msec.
  // Trigger OVF ISR to set tick flag.

  TCCR1B =  (1 << WGM13)|(1 << WGM12); // start FAST PWM mode 14 setup
  TCCR1A =  (1 << WGM11)|(0 << WGM10); // finish FAST PWM setup
  TCCR1B |= (0 << CS12)|(1 << CS11)|(0 << CS10); // prescale 8 -> 0.5 usec/count
  ICR1 = (2000*TSAMP_MSEC)-1; // period in msec at 0.5 usec/count
  TIMSK1 |= (1 << TOIE1); // enable timer overflow interrupt (cycle length)
  
  sei(); // enable global interrupts
}

//**********************************************************************
ISR(TIMER1_OVF_vect) // 10 msec sample flag
{  
  isSample = true;  // set flag enabling loop advance
}
