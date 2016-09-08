//**********************************************************************
//**********************************************************************
//                            TIMER CODE
//**********************************************************************
//**********************************************************************

void initTimer(void)
{
  cli(); // disable global interrupts 

  //--------------------------------------------------------------------
  // Use Timer 2 (16 bit) for pwm generation.
  // Prescale = 1: 16 MHz counter clock
  // FAST PWM, 8-bit (Mode 7): 62.5 kHz PWM frequency
  // Direct drive Arduino d5 (OCR3A register)

  TCCR2B =  (1 << WGM22); // start FAST PWM mode 7 setup to allow for OCR2A
  TCCR2A =  (1 << WGM21)|(1 << WGM20); // finish FAST PWM setup
  TCCR2B |= (0 << CS22)|(0 << CS21)|(1 << CS20); // prescale 1
  TCCR2A |= (1 << COM2A1)|(0 << COM2A0); // non-inverting direct drive OCR2A (d11) 
//  TCCR3A |= (1 << COM2A1)|(1 << COM2A0); // inverting direct drive OCR2A (d11) 
  OCR2A = 255; // 0...255, init to 50% duty cycle, set to half of 9 bit since 2^8=256 versus 2^9=512, OCR2A comes out on PB3 which is pin 17 atmel which is D11, ORC2B comes out on PD3 which 
  
  sei(); // enable global interrupts
}
