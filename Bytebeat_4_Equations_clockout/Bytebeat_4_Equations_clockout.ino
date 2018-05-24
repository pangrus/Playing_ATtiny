///////////////////////////////////////////////////
//                  __ __                        //
//  .---.-.--.--.--|  |__|.-----.                //
//  |  _  |  |  |  _  |  ||  _  |                //
//  |___._|_____|_____|__||_____|                //
//   __                __     __         __      //
//  |  |--.---.-.----.|  |--.|  |.---.-.|  |--.  //
//  |     |  _  |  __||    < |  ||  _  ||  _  |  // 
//  |__|__|___._|____||__|__||__||___._||_____|  //
//                                               //
///////////////////////////////////////////////////
// One line code symphony with clock output 
// and 4 equations
// Written by Pangrus 
// 2017
// Inspired by http://countercomplex.blogspot.com/2011/10/algorithmic-symphonies-from-one-line-of.html
// This example code is in the public domain.



int t=0;
int clockTime = 1023;
int clockReset = 1023;
int clockOutput = 1;
int selezioneEquazione;
int parametro1;

void setup() {
  // Enable 64 MHz PLL and use as source for Timer1
  PLLCSR = 1<<PCKE | 1<<PLLE;     
  // Set up Timer/Counter1 for PWM output
  TIMSK = 0;                              // Timer interrupts OFF
  TCCR1 = 1<<PWM1A | 2<<COM1A0 | 1<<CS10; // PWM A, clear on match, 1:1 prescale
  GTCCR = 1<<PWM1B | 2<<COM1B0;           // PWM B, clear on match
  OCR1A = 128; 
  OCR1B = 128;               // 50% duty at start
  // Set up Timer/Counter0 for 8kHz interrupt to output samples.
  TCCR0A = 3<<WGM00;                      // Fast PWM
  TCCR0B = 1<<WGM02 | 2<<CS00;            // 1/8 prescale
  TIMSK = 1<<OCIE0A;                      // Enable compare match
  OCR0A = 124;                            // Divide by 1000
  pinMode (0,OUTPUT);
  pinMode (1,OUTPUT);
  clockTime = 1023; 
  clockReset = 1023;
}

void loop() {
  selezioneEquazione = analogRead(2)/256;
  parametro1 = analogRead(3)/128;
}

ISR(TIMER0_COMPA_vect) {
  switch(selezioneEquazione)
  {
  case 0:
    OCR1A = ((2*(t&1)-1)*t*parametro1)-(t>>(1+parametro1/256));  //weaoowwwoooooiiinnn inspired by https://www.reddit.com/r/bytebeat/comments/20km9l/cool_equations/

    break;
  case 1:
    OCR1A = (t & (t>>15+(t>>(8+parametro1&t))))*t ;   
    break;
  case 2:
   OCR1A = (t*(-(t>>8|t|t>>9|t>>parametro1)))^t;  //complex noise
    
    //    OCR1A = t>>5|t>>(3+parametro1);
    //    OCR1A = (t*(-(t>>8|t|t>>9|t>>13)))^t;  //complex noise
    //    OCR1A =(t*(-(t>>8|t|t>>9|t>>17)))^t;  
    //    OCR1A = t>>(t%(t>>1&t));              // Noisecore
    //    OCR1A = t>>(8/((t/32)%3));            // 8 bars
    //    OCR1A = t/((t%(t>>13&t)));            // bleeps  
    //    OCR1A = t>>5|t>>3;                    // kick andbass
    break;
  case 3:
    OCR1A = t>>(t%(t>>parametro1&t));            
    break;
  }
  if (clockTime>=clockReset)
  {
    clockTime=0;
    clockReset=1023;
    clockOutput=!clockOutput;
    digitalWrite (0,clockOutput);
  }
  t++;
  clockTime++;
}


