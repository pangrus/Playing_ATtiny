// Spread Freq
// by Pangrus 2017
// Based on Tiny Synth v4 by David Johnson-Davies - www.technoblogy.com - 27th March 2016
// CC BY 4.0
// Licensed under a Creative Commons Attribution 4.0 International license: 
// http://creativecommons.org/licenses/by/4.0/
// Modified by Pangrus to adapt it on the HNG Attiny85 hardware 

int frequenza1;
int frequenza2;

// Note buffer
volatile unsigned int Acc[] = {
  0, 0, 0, 0};
volatile unsigned int Freqs[] = {
  0, 0, 0, 0 };

char Octave = 0, LastIndex = 0, Duration = 4;

// Generate triangle waves on 4 channels
ISR(TIMER0_COMPA_vect) {
  signed char Mask, Temp, Sum=0;
  for (int c=0; c<4; c++) {
    Acc[c] = Acc[c] + Freqs[c];
    Temp = Acc[c] >> 8;
    Mask = Temp >> 15;
    Sum = Sum + ((char)(Temp ^ Mask) >> 1);
  }
  OCR1A = Sum;
}

void setup() {
  pinMode(1, OUTPUT);                                // Pin 6 corrisponde a OC1A,PB1
  TCCR0A = 0;                                        // Reset del TCCR0A registro di controllo dei timer
  TCCR0B = 0;                                        // Reset del TCCR0B registro di controllo dei timer
  TIMSK = 1<<OCIE0A;                                 // Setto OCIEOA per abilitare l'interrupt del timer 0
  TCCR0A = 1<<WGM00 | 1<<WGM01;                      // Fast PWM
  TCCR0B = 1<<WGM02 | 1<<CS02| 0<<CS01 | 0<<CS00;    // Fast PWM | Setto CS02 per avere fClock/256 = 8000KHz / 256 = 31.250 KHz  
  TCCR1  = 1<<PWM1A | 2<<COM1A0 | 1<<CS10;           // Set up Watchdog timer for 8 Hz interrupt for ticks timer.
}


void loop() {
 frequenza1 = analogRead (2) + 200;
 frequenza2 = analogRead (3);

//  Freqs[Chan++] = Scale[Index] >> (4 - Octave);

 Freqs[0] = frequenza1; 
 Freqs[1] = frequenza1 - frequenza2/5;
 Freqs[2] = frequenza1 - frequenza2/7;
 Freqs[3] = frequenza1 + frequenza2/11;
 }

