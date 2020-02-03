// One line code symphony
// Pangrus 2017
// Inspired by: http://countercomplex.blogspot.com/2011/10/algorithmic-symphonies-from-one-line-of.html
// This example code is in the public domain.

int outputPin = 1;
int controlPin1 = 2;
int controlPin2 = 3;

long t = 0; 
int output = 0; 
 
void setup () { 
   // Enable 64 MHz PLL and use as source for Timer1
  PLLCSR = 1 << PCKE | 1 << PLLE;
  // Set up Timer/Counter1 for PWM output
  TIMSK = 0;                              // Timer interrupts OFF
  TCCR1 = 1 << PWM1A | 2 << COM1A0 | 1 << CS10; // PWM A, clear on match, 1:1 prescale
  GTCCR = 1 << PWM1B | 2 << COM1B0;       // PWM B, clear on match
  OCR1A = 128;
  OCR1B = 128;               // 50% duty at start
  // Set up Timer/Counter0 for 8kHz interrupt to output samples.
  TCCR0A = 3 << WGM00;                    // Fast PWM
  TCCR0B = 1 << WGM02 | 2 << CS00;        // 1/8 prescale
  TIMSK = 1 << OCIE0A;                    // Enable compare match
  OCR0A = 124;                            // Divide by 1000 
  pinMode (outputPin, OUTPUT);
}

void loop () {
  int parameter1 = (analogRead(controlPin1)/64) + 1; 
  int parameter2 = (analogRead(controlPin2)/128) + 1;
  output = (t>>parameter1|t|t>>(t>>parameter1))*parameter2;;
  analogWrite (outputPin, output);
  t++;
}


