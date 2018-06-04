// Shapable LFO per Attiny 
// Pangrus 2016

int time;            // Asse dei tempi
int delayTime;       // Tempo di delay
int output;
float inc;           // Incremento ogni step di time
float dec;           // Decremento ogni step di time
float posX = 0;      // Posizione del pitch del LFO


void setup() {
  pinMode(1, OUTPUT);      // Uscita su pin 6 - PB1
  pinMode(2, INPUT);
  pinMode(3, INPUT);

  // Setto la modalità fast PWM in modo che la frequenza del pwm esca dal campo audio 

  // Control Register A for Timer/Counter-0 (Timer/Counter-0 is configured using two registers: A and B)
  // TCCR0A is 8 bits: [COM0A1:COM0A0:COM0B1:COM0B0:unused:unused:WGM01:WGM00]
  // 2<<COM0A0: sets bits COM0A0 and COM0A1, which (in Fast PWM mode) clears OC0A on compare-match, and sets OC0A at BOTTOM
  // 2<<COM0B0: sets bits COM0B0 and COM0B1, which (in Fast PWM mode) clears OC0B on compare-match, and sets OC0B at BOTTOM
  // 3<<WGM00: sets bits WGM00 and WGM01, which (when combined with WGM02 from TCCR0B below) enables Fast PWM mode
  // http://matt16060936.blogspot.co.uk/2012/04/attiny-pwm.html  
  TCCR0A = 2<<COM0A0 | 2<<COM0B0 | 3<<WGM00;

  // Control Register B for Timer/Counter-0 (Timer/Counter-0 is configured using two registers: A and B)
  // TCCR0B is 8 bits: [FOC0A:FOC0B:unused:unused:WGM02:CS02:CS01:CS00]
  // 0<<WGM02: bit WGM02 remains clear, which (when combined with WGM00 and WGM01 from TCCR0A above) enables Fast PWM mode
  // 1<<CS00: sets bits CS01 (leaving CS01 and CS02 clear), which tells Timer/Counter-0 to not use a prescalar
  // http://matt16060936.blogspot.co.uk/2012/04/attiny-pwm.html
  TCCR0B = 0<<WGM02 | 1<<CS00;
}

void loop() {
  for (time=1; time <=256; time++)
  {
    posX = analogRead(2)/4+1;
    delayTime= (1023-analogRead(3))*3;
    inc = 255 / posX;                    // calcolo l'incremento ogni step di time
    dec = 255 / (256-posX);              // calcolo il decremento ogni step di time
    if (time < posX) output= time*inc;
    if (time >= posX) output= (256-time)*dec;
    analogWrite(1,output);
    delay(delayTime);
  }
}




