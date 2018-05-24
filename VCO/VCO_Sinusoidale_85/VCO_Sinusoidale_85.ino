//Sinusoide_85

#include <avr/pgmspace.h>

PROGMEM prog_uchar sinusoide[] = {
  128,129,131,134,137,140,143,146,149,152,155,158,161,164,167,170,173,176,179,182,185,187,190,
  193,195,198,201,203,206,208,210,213,215,217,219,222,224,226,228,230,231,233,235,236,238,240,
  241,242,244,245,246,247,248,249,250,251,251,252,253,253,254,254,254,254,254,255,254,254,254,
  254,254,253,253,252,251,251,250,249,248,247,246,245,244,242,241,240,238,236,235,233,231,230,
  228,226,224,222,219,217,215,213,210,208,206,203,201,198,195,193,190,187,185,182,179,176,173,
  170,167,164,161,158,155,152,149,146,143,140,137,134,131,128,125,122,119,116,113,110,107,104,
  101,98,95,92,89,86,83,80,77,74,71,69,66,63,61,58,55,53,50,48,46,43,41,39,37,34,32,30,28,26,25,
  23,21,20,18,16,15,14,12,11,10,9,8,7,6,5,5,4,3,3,2,2,2,2,2,1,2,2,2,2,2,3,3,4,5,5,6,7,8,9,10,11,12,14,
  15,16,18,20,21,23,25,26,28,30,32,34,37,39,41,43,46,48,50,53,55,58,61,63,66,69,71,74,77,80,83,86,
  89,92,95,98,101,104,107,111,114,119,123,127,};

int end_point = 0;
byte p = 0;
char output;
int volume;

void setup() {
  // Enable 64 MHz PLL and use as source for Timer1
  PLLCSR = 1<<PCKE | 1<<PLLE;     
  // Set up Timer/Counter1 for PWM output
  TIMSK = 0;                              // Timer interrupts OFF
  TCCR1 = 1<<PWM1A | 2<<COM1A0 | 1<<CS10; // PWM A, clear on match, 1:1 prescale
  GTCCR = 1<<PWM1B | 2<<COM1B0;           // PWM B, clear on match
  OCR1A = 128; 

  // Set up Timer/Counter0 for 8kHz interrupt to output outputs.
  TCCR0A = 3<<WGM00;                      // Fast PWM
  TCCR0B = 1<<WGM02 | 2<<CS00;            // 1/8 prescale
  TIMSK = 1<<OCIE0A;                      // Enable compare match
  OCR0A = 124;                            // Divide by 1000
  pinMode (1,OUTPUT);
}

void loop() {
  OCR0A =  (63-analogRead (3)/16)*(3-analogRead(2)/256);
}

ISR(TIMER0_COMPA_vect) {
  output = pgm_read_byte(&sinusoide[p++]);
  OCR1A = output;
}



