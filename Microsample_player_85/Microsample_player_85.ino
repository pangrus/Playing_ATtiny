//Microsample player 85
//Pangrus' fun


#include <avr/pgmspace.h>

PROGMEM prog_uchar sample_wave[] = {
  33,13,0,0,128,128,128,128,128,128,129,129,128,128,126,125,125,125,126,127,126,127,128,127,128,128,127,125,127,131,133,131,131,133,133,130,129,130,130,131,134,136,134,130,128,127,125,123,122,121,118,117,123,127,125,126,129,125,121,118,114,116,124,132,138,142,147,144,139,133,122,118,127,140,145,146,144,137,125,120,123,127,123,117,121,123,121,120,119,121,118,113,106,105,111,120,137,150,157,149,
  141,137,128,123,128,137,150,155,148,139,129,119,117,120,121,113,110,112,115,120,125,129,129,118,105,106,117,137,149,150,146,134,126,124,127,133,137,148,159,156,137,119,115,116,121,132,130,117,112,116,118,114,115,123,118,103,107,125,144,146,141,145,140,127,119,126,135,139,148,162,163,143,124,115,112,112,125,134,126,116,118,125,120,112,110,101,96,106,132,149,143,140,137,129,124,124,129,137,149,168,
  171,154,135,123,119,117,116,123,121,116,115,123,123,116,112,102,98,115,143,149,134,130,134,129,123,128,130,135,143,158,162,144,126,118,117,122,126,129,122,112,117,126,125,126,119,105,107,132,150,144,136,135,125,116,119,121,124,134,149,158,153,139,124,111,111,126,133,126,114,115,124,125,126,128,116,111,127,146,144,134,132,134,126,120,124,131,133,138,150,153,137,118,108,115,128,129,120,112,112,123,
  124,129,122,109,119,137,148,139,127,134,129,122,128,135,141,143,148,159,148,129,118,117,119,122,124,114,105,111,118,122,117,97,97,122,147,147,138,146,146,127,124,132,138,144,149,160,160,136,117,113,118,124,128,124,108,105,116,119,114,101,102,117,137,148,137,132,134,124,122,130,138,145,149,156,159,143,126,118,120,130,133,129,117,111,116,119,117,102,99,120,138,142,136,135,132,118,114,127,136,139,
  144,151,151,135,119,113,121,133,134,133,125,117,118,125,124,109,107,124,142,144,139,141,135,114,109,124,136,144,147,152,146,125,113,106,110,125,131,130,124,122,123,122,118,105,108,128,142,142,140,145,138,118,120,130,130,141,152,159,149,127,120,117,115,122,126,126,116,114,119,119,115,105,116,135,137,132,132,139,135,119,122,134,135,144,155,162,151,124,118,123,125,123,122,124,119,113,111,111,102,105,
  126,142,137,130,139,142,123,112,125,136,134,146,164,164,144,125,126,125,121,124,126,123,118,117,114,108,97,101,125,137,128,123,138,142,122,117,131,136,130,145,168,166,147,133,138,136,118,114,120,113,111,121,121,106,92,105,133,137,125,128,146,138,113,113,130,133,129,147,162,153,142,140,147,139,124,125,124,110,106,113,118,110,95,106,128,133,125,125,141,142,124,122,132,133,132,143,153,148,143,142,
  144,136,124,123,123,115,111,112,115,115,109,106,118,127,125,125,131,138,136,129,130,135,134,133,137,139,135,136,142,137,132,137,137,127,120,122,125,121,115,119,122,114,116,124,123,120,125,135,135,134,134,134,130,120,117,122,129,131,131,135,139,139,135,132,134,133,127,123,122,122,122,119,116,120,127,129,130,137,141,138,134,132,126,122,125,129,131,132,132,130,130,127,124,122,123,122,122,121,120,119,
  118,122,127,129,132,143,142,133,134,133,130,129,128,127,130,132,128,127,133,138,134,128,127,126,123,117,116,114,113,119,124,124,131,139,140,139,138,135,132,130,126,122,127,132,127,123,123,127,126,126,133,136,131,124,123,118,116,121,124,126,130,136,135,134,133,133,133,133,130,127,129,133,131,127,124,125,128,126,125,127,130,126,126,127,124,123,120,120,123,129,129,127,127,127,129,130,131,134,138,136,
  134,132,130,132,130,126,127,129,126,124,125,126,125,126,126,124,127,127,122,121,124,130,131,130,130,133,134,131,131,132,129,127,128,128,124,124,126,128,129,127,128,130,129,127,127,130,129,122,121,127,130,129,131,134,138,138,134,131,126,123,124,123,122,121,122,126,126,124,127,128,130,131,130,130,130,131,128,128,129,128,130,131,131,137,137,131,127,127,127,123,119,118,120,124,125,124,130,132,129,129,
  133,133,129,130,132,129,125,126,131,133,132,129,130,129,127,126,127,126,125,123,119,121,126,128,130,131,129,128,130,130,127,127,131,131,129,128,129,132,134,133,130,128,131,132,128,124,123,125,126,123,123,125,123,123,127,129,129,131,132,129,125,126,127,130,133,131,131,133,132,128,127,129,130,126,126,130,129,127,129,130,128,126,124,121,120,123,124,126,128,128,127,128,130,133,134,134,137,135,131,128,
  126,125,126,126,126,128,128,127,125,125,124,124,122,125,127,126,125,126,129,129,128,130,134,135,135,135,133,131,129,126,124,126,127,129,130,128,127,128,125,122,124,129,131,129,127,126,126,124,124,124,128,131,131,131,129,127,127,130,128,127,129,130,128,128,130,131,128,124,125,129,129,126,128,130,129,130,131,126,124,129,129,129,131,130,129,127,126,126,128,131,128,122,125,125,123,126,129,130,132,132,
  128,127,126,127,129,131,130,128,129,129,128,127,131,135,131,130,130,130,126,124,123,123,123,124,126,129,130,128,130,129,125,125,125,127,131,132,130,129,130,130,126,126,130,133,132,132,130,127,125,122,120,123,124,127,131,134,132,123,123,131,131,131,135,135,128,121,125,131,131,127,125,127,127,126,128,127,129,132,128,122,121,125,131,135,132,118,112,123,133,131,129,135,139,135,130,130,129,124,127,130,
  128,124,125,128,129,125,124,125,126,129,133,131,124,118,131,142,141,136,128,127,126,125,125,121,119,126,125,128,124,121,124,122,132,119,124,128,135,137,136,132,138,127,133,134,133,128,129,126,132,122,127,125,127,128,127,132,127,125,129,123,118,118,122,131,127,125,131,122,126,131,136,131,126,131,139,135,127,124,126,124,128,127,130,134,134,129,129,131,131,130,126,128,126,118,120,125,125,129,127,129,
  124,119,126,128,125,119,123,129,131,139,139,142,142,134,132,133,129,129,133,136,132,122,118,122,120,116,117,122,126,119,119,114,114,120,121,131,134,136,142,143,142,140,138,143,139,138,136,134,135,131,130,119,117,117,115,119,118,119,121,117,116,107,106,114,123,132,133,143,145,140,140,136,138,137,140,147,147,142,135,132,133,130,123,119,115,114,117,116,112,107,106,108,114,123,122,127,132,130,139,143,
  144,142,139,139,148,152,147,138,139,138,130,123,119,118,114,114,116,108,102,102,103,108,122,127,129,130,132,143,144,145,146,142,146,143,145,145,137,138,139,132,126,119,118,117,112,112,111,105,105,105,110,112,119,130,135,144,140,140,142,142,145,138,137,140,142,138,127,135,137,135,137,127,124,122,120,113,103,106,109,114,109,107,112,122,136,138,138,135,138,145,146,140,137,141,145,144,137,129,129,133,
  132,133,126,122,119,113,115,106,107,113,116,116,115,118,121,134,139,137,135,139,142,135,135,138,142,142,141,142,133,128,129,129,129,126,121,120,112,113,112,108,115,121,127,122,122,123,128,140,139,136,126,127,132,129,132,132,139,147,146,141,133,130,132,130,130,128,121,118,115,111,111,113,120,125,130,127,125,123,127,134,132,128,120,125,130,127,131,136,146,148,146,144,134,134,132,128,123,119,119,116,
  110,112,114,118,126,134,142,133,129,127,121,126,124,123,120,121,129,128,132,138,141,148,151,145,132,127,128,125,121,119,116,121,123,126,124,122,125,131,138,132,118,112,109,116,124,127,123,122,130,135,138,142,147,151,155,150,138,129,130,127,119,115,112,116,120,120,120,118,122,127,129,127,127,120,118,117,120,125,122,129,129,132,137,141,150,151,152,153,150,143,132,129,120,113,110,104,107,114,119,119,
  116,118,124,133,135,134,125,122,121,117,126,124,123,131,136,144,144,145,150,149,150,145,139,130,129,121,113,108,101,105,114,125,125,124,122,129,139,136,136,129,117,114,112,119,125,123,130,130,134,137,137,147,153,149,145,144,139,126,123,118,113,111,112,118,118,123,123,122,125,129,135,133,135,126,115,114,117,133,135,130,128,126,134,134,133,137,142,146,141,136,130,129,125,120,117,110,110,116,122,133,
  140,141,139,133,129,127,121,108,106,113,130,135,126,125,125,130,129,127,133,144,146,140,137,137,139,132,121,115,117,121,121,124,137,151,150,136,121,116,114,110,105,95,105,120,136,139,128,132,138,137,130,128,136,150,147,140,142,146,144,125,111,114,122,119,111,119,139,152,144,126,114,111,106,101,100,100,117,134,151,155,144,147,140,123,114,115,129,142,146,148,153,157,144,120,111,115,118,110,104,114,
  131,147,144,130,122,120,109,99,105,107,117,131,144,154,147,138,127,114,108,118,137,154,162,164,163,160,144,116,101,101,105,104,95,110,138,156,156,143,128,113,101,91,96,107,109,122,143,161,166,143,131,126,119,121,123,140,158,158,153,146,141,121,98,96,103,116,120,125,145,157,159,146,122,108,94,84,82,96,120,126,139,161,177,171,135,119,115,112,116,117,135,161,166,155,142,136,120,96,92,109,
  133,137,129,139,148,147,127,104,100,98,92,89,105,136,144,147,158,169,165,130,108,103,109,117,117,137,173,181,163,143,132,116,92,87,104,128,136,128,136,151,147,121,103,106,111,98,86,103,139,148,136,144,166,172,134,100,106,121,128,127,138,169,180,161,130,118,119,101,88,101,131,143,135,136,143,140,119,100,96,103,103,96,103,138,158,141,140,160,172,146,107,106,119,124,122,127,156,176,165,139,
  126,124,115,89,88,119,147,147,127,128,136,124,104,101,113,120,107,99,122,151,145,130,142,159,152,118,101,119,132,132,130,150,177,169,144,126,124,120,101,85,103,136,147,125,116,132,132,117,103,112,126,125,113,110,134,146,125,116,136,157,149,120,121,138,143,141,135,149,162,146,125,114,114,115,99,95,120,151,153,129,122,130,124,107,100,116,132,123,105,106,134,144,123,125,147,166,154,116,119,141,
  142,128,120,143,159,146,125,121,135,131,101,96,121,142,130,105,112,133,131,111,105,128,145,128,105,106,136,142,113,116,150,178,163,124,130,146,132,110,108,136,155,143,122,124,142,130,98,93,114,134,130,114,120,139,138,120,114,133,146,124,99,102,125,137,120,123,155,178,166,130,124,133,121,104,102,126,152,152,140,135,142,129,100,88,97,121,130,124,131,144,146,131,118,122,130,129,115,108,117,130,
  137,133,143,163,164,148,121,112,116,106,101,111,134,152,149,140,139,138,126,102,93,104,123,134,132,140,146,142,129,117,123,130,130,125,117,117,120,128,133,128,141,152,151,137,117,118,117,111,113,126,142,140,135,136,138,134,118,110,109,113,123,125,135,143,140,139,136,136,131,128,132,127,118,105,106,127,127,126,136,149,158,135,116,116,110,111,109,119,138,149,151,139,138,140,129,117,107,115,128,128,
  128,132,142,146,135,127,125,132,131,114,103,102,116,131,124,128,145,155,152,126,118,122,115,106,103,121,143,150,145,145,152,146,124,111,111,120,123,119,127,136,139,140,135,133,126,123,119,113,104,103,115,130,128,126,136,153,154,129,119,125,125,118,108,122,148,153,145,143,151,152,131,115,109,114,118,111,115,128,139,138,128,127,129,126,119,108,103,109,118,126,123,128,143,152,151,136,132,135,129,120,
  112,123,140,144,142,142,146,145,135,127,119,114,114,112,114,115,122,129,131,130,127,126,124,118,110,110,121,133,128,125,136,147,150,138,126,128,132,131,120,118,132,143,146,146,142,137,134,129,121,114,116,119,117,114,120,130,133,128,125,124,128,126,120,119,123,130,130,125,129,134,135,132,133,135,132,128,127,122,122,125,131,132,130,131,139,141,135,127,129,135,132,125,123,127,133,128,120,126,135,128,
  116,116,123,123,115,114,124,131,128,126,128,133,131,123,118,119,123,123,129,138,146,148,147,146,143,134,126,124,124,124,126,129,131,131,130,132,134,128,118,116,117,112,109,115,124,126,128,130,131,129,123,121,123,125,127,128,132,137,139,136,135,136,132,129,128,128,131,134,134,138,141,135,132,132,129,121,118,120,121,121,119,120,128,132,127,122,121,121,119,119,122,125,128,131,134,134,132,127,128,130,
  130,128,131,135,132,127,128,134,139,134,128,129,131,130,127,127,130,129,125,124,130,133,131,127,125,126,125,121,122,125,128,127,125,125,127,124,120,123,125,122,123,126,128,125,129,135,137,139,142,140,134,127,122,119,123,125,124,127,131,133,134,136,136,134,131,126,127,133,132,131,132,133,131,126,123,118,114,110,109,112,116,118,123,130,137,138,138,136,131,127,122,119,120,127,132,135,141,142,140,139,
  138,133,127,122,123,128,130,128,130,135,136,131,126,126,127,123,118,119,124,126,123,122,123,124,125,124,122,122,127,126,123,126,129,132,135,134,132,135,136,131,130,132,133,132,132,129,131,133,133,131,130,130,127,125,123,121,123,126,126,124,124,126,126,125,126,127,125,126,124,120,120,123,125,126,130,132,132,132,133,134,134,133,132,130,129,129,129,131,133,132,131,131,130,129,127,128,130,128,129,131,
  128,126,127,127,126,127,127,122,120,122,122,122,124,126,124,123,125,126,129,130,128,127,126,127,130,130,129,130,134,134,131,132,133,132,131,129,130,133,131,131,131,128,131,132,129,127,129,125,118,120,125,126,127,130,129,126,127,129,128,124,123,122,121,120,123,127,128,127,128,131,130,129,128,129,129,128,131,135,134,131,131,130,132,133,134,133,132,130,130,131,131,128,127,127,122,120,122,125,123,125,
  128,129,131,131,128,125,127,124,120,120,122,121,120,125,130,131,129,130,131,129,131,132,132,132,134,137,132,130,134,133,132,130,129,128,127,127,125,126,128,129,128,127,126,124,125,127,126,124,124,124,124,125,128,128,129,128,127,123,123,128,127,126,126,128,131,130,130,129,129,134,137,133,127,127,132,130,128,128,131,130,130,131,129,129,130,128,126,125,126,126,125,122,126,131,128,128,129,128,129,126,
  123,121,122,128,131,122,120,128,127,126,131,132,131,128,124,127,129,127,132,133,131,133,135,135,138,137,133,131,131,131,129,125,125,129,126,124,123,122,120,119,120,121,123,126,126,120,120,126,129,129,127,128,130,127,122,125,128,129,131,132,134,137,140,141,141,140,139,137,135,129,127,127,126,127,127,126,122,119,119,118,119,121,122,119,118,118,117,122,127,128,128,128,128,128,131,135,135,135,135,134,
  133,133,134,137,138,137,134,131,129,128,128,127,129,132,130,125,124,125,122,119,121,124,123,124,122,117,118,122,125,125,122,123,126,128,128,130,132,132,131,133,135,136,138,139,138,140,137,130,127,128,127,125,126,128,127,125,126,127,127,126,126,126,125,125,124,124,123,122,124,125,126,127,127,127,128,128,129,130,131,129,129,131,130,130,130,131,129,129,130,129,130,131,130,130,129,129,128,127,127,126,
  127,127,127,126,126,126,127,127,127,127,127,127,127,127,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,129,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,
};


unsigned int end_point = 0;
unsigned int p = 0;

void setup() {
  TIMSK = 1<<OCIE0A;                      // Setto OCIEOA per abilitare l'interrupt del timer 0
  TCCR0A = 3<<WGM00;                      // Fast PWM
  TCCR0B = 1<<WGM02 | 2<<CS00;            // 1/8 prescale
  TCCR1 = 1<<PWM1A | 2<<COM1A0 | 1<<CS10; 
  OCR1A = 128; 
  pinMode (1,OUTPUT);
}

void loop() {
  OCR0A =  analogRead (2)/4;
  end_point = (analogRead(3)*3);
}

// Interrupt
ISR(TIMER0_COMPA_vect) {
  char sample = pgm_read_byte(&sample_wave[p++]);
  OCR1A = sample;
  if (p > end_point) {
    p=0;
    OCR1A = 0;
  }
}


