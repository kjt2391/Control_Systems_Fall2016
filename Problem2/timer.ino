//**********************************************************************
//**********************************************************************
//                            TIMER CODE
//**********************************************************************
//**********************************************************************

void initTimer(void)
{
  cli(); // disable global interrupts 

  //--------------------------------------------------------------------
  // Use Timer 3 (16 bit) for pwm generation.
  // Prescale = 1: 16 MHz counter clock
  // FAST PWM, 9-bit (Mode 6): 31.25 kHz PWM frequency
  // Direct drive Arduino d5 (OCR3A register)

  TCCR3B =  (0 << WGM33)|(1 << WGM32); // start FAST PWM mode 6 setup
  TCCR3A =  (1 << WGM31)|(0 << WGM30); // finish FAST PWM setup
  TCCR3B |= (0 << CS32)|(0 << CS31)|(1 << CS30); // prescale 1
  TCCR3A |= (1 << COM3A1)|(0 << COM3A0); // non-inverting direct drive OCR3A (d5) 
//  TCCR3A |= (1 << COM3A1)|(1 << COM3A0); // inverting direct drive OCR3A (d5) 
  OCR3A = 255; // 0...511, init to 50% duty cycle
  
  sei(); // enable global interrupts
}
