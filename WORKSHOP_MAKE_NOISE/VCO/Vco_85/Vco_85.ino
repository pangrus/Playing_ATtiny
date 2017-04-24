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

//Simple VCO
//AHL 2016

void setup(){
  pinMode(1, OUTPUT);                                 // Pin 6 corrisponde a OC1A,PB1
}

void loop()
{
  int freq = map (analogRead (3),0,1023,255,127);     // Leggo il pin 3 (ADC2) per la frequenza
  int ottava=analogRead (2)/256;                      // Leggo il pin 2 (ADC3), divido per 256 avro' 4 ottave di escursione
  
  TCCR1 = 0x90 | (9-ottava);                          // Seleziono CTC MODE (Clear Timer on Compare mode) 
                                                      // Usiamo il pin 6 (OC1A), ogni volta che il timer TCNT1 supera OCR1C il pin cambia di stato
                                                      // Da datasheet, dobbiamo settare il pin 7 e il pin 4 del registro TCCR1
                                                      // 0x90 in binario e' 1001000
  OCR1C = freq;                                       // Setto OCR1C alla frequenza da suonare
  delay (5);  
}



