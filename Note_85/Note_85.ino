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

//Note85
//AHL 2016

// Note
const int Do  = 239;                // Clock/ Prescaler/ Frequenza nota = 8000000 Hz/ 128 / 261,6 Hz = 238,91
const int Do_diesis = 225;          // Clock/ Prescaler/ Frequenza nota = 8000000 Hz/ 128 / 277,2 Hz = 225,47
const int Re  = 213;                // Clock/ Prescaler/ Frequenza nota = 8000000 Hz/ 128 / 293,7 Hz = 212,80    
const int Re_diesis = 201;          // Clock/ Prescaler/ Frequenza nota = 8000000 Hz/ 128 / 311,1 Hz = 200,90
const int Mi  = 190;                // Clock/ Prescaler/ Frequenza nota = 8000000 Hz/ 128 / 329,6 Hz = 189,62
const int Fa  = 179;                // Clock/ Prescaler/ Frequenza nota = 8000000 Hz/ 128 / 349,2 Hz = 178,98
const int Fa_diesis = 169;          // Clock/ Prescaler/ Frequenza nota = 8000000 Hz/ 128 / 370,0 Hz = 168,92
const int Sol  = 159;               // Clock/ Prescaler/ Frequenza nota = 8000000 Hz/ 128 / 392,0 Hz = 159,44
const int Sol_diesis = 150;         // Clock/ Prescaler/ Frequenza nota = 8000000 Hz/ 128 / 415,3 Hz = 150,49
const int La  = 142;                // Clock/ Prescaler/ Frequenza nota = 8000000 Hz/ 128 / 440,0 Hz=  142,05
const int La_diesis = 134;          // Clock/ Prescaler/ Frequenza nota = 8000000 Hz/ 128 / 466,2 Hz = 134,06
const int Si  = 127;                // Clock/ Prescaler/ Frequenza nota = 8000000 Hz/ 128 / 493,9 Hz = 126,54

void setup(){
  pinMode(1, OUTPUT);               // Pin 6 corrisponde a OC1A,PB1
}

void loop()
{
  int durata=analogRead (2);         // Leggo il pin 3 (ADC2) per la durata della nota da suonare
  int ottava=analogRead (3)/256;     // Leggo il pin 2 (ADC3), divido per 256 avro' 4 ottave di escursione

  Suona(Sol, ottava, durata);        // Chiamo l'astronave      
  Suona(La, ottava, durata);
  Suona(Fa, ottava, durata);
  Suona(Fa, ottava-1, durata);
  Suona(Do, ottava, durata*4);
  delay (durata*2);
}

void Suona(unsigned char div, unsigned char ott, unsigned long dur)
{
  TCCR1 = 0x90 | (8-ott);           // Seleziono CTC MODE (Clear Timer on Compare mode) 
                                    // Usiamo il pin 6 (OC1A), ogni volta che il timer TCNT1 supera OCR1C il pin cambia di stato
                                    // Da datasheet, dobbiamo settare il pin 7 e il pin 4 del registro TCCR1
                                    // 0x90 in binario e' 1001000

  OCR1C = div;                      // Setto OCR1C alla nota da suonare         

  delay(dur);                       // Attendo la durata della nota  

  TCCR1 = 0x90 ;                    // Fermo il counter
}



