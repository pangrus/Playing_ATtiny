//Super basic random LFO for ATtiny Multiboard (skin up version)
//Pangrus 2018

int valore;
int prossimoValore;

void setup() {
  pinMode (1, OUTPUT);
  TCCR0A = 2 << COM0A0 | 2 << COM0B0 | 3 << WGM00;
  TCCR0B = 0 << WGM02 | 1 << CS00;
}

void loop() {
  if (valore > prossimoValore) valore--;
  if (valore < prossimoValore) valore++;
  if (valore == prossimoValore) prossimoValore = random (0, map(analogRead (2),0,1023,0,255));
  
  analogWrite (1, valore);
  delay (1024 - analogRead (3));
}






