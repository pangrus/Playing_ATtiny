// MiniDrone_saw
// Minimal Drone Machine
// Basato su "Tiny Synth v4" di David Johnson-Davies -  http://www.technoblogy.com - 27 Marzo 2016
// Modificato da Pangrus per adattarlo all'hardware HNG (Attiny85)
// Creative Commons Attribution 4.0 International license: 
// http://creativecommons.org/licenses/by/4.0/

int frequenza1;
int frequenza2;
unsigned int Acc[]   = {0, 0, 0, 0};
unsigned int Freqs[] = {0, 0, 0, 0};

// Genera quattro onde dente di sega a diverse frequenze
ISR(TIMER0_COMPA_vect) {
  byte Sum=0;
  for (int c=0; c<4; c++) {
    Acc[c] = Acc[c] + Freqs[c];
    Sum = Sum + Acc[c]/2048;
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
 frequenza1 = analogRead (2) + 100;
 frequenza2 = analogRead (3) + 100;


// Rapporti tra frequenze
// 1/1 Unisono
// 5/4 Terza
// 4/3 Quarta
// 3/2 Quinta
// 2/1 Ottava

 Freqs[0] = frequenza1; 
 Freqs[1] = frequenza2;
 Freqs[2] = frequenza1*5/4;
 Freqs[3] = frequenza2*3/2;
 }

