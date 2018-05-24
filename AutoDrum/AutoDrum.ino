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
//                                               //
//                 AutoDrum                      //  
//         Autogenerative drum machine           //
//                                               //
//       Drum sound generation based on          //
//      'AVR cheap bass  drum synthesis'         //
//              by Alex Allmont                  //
//     http://www.alexallmont.com/?p=178con      //
//                                               //
///////////////////////////////////////////////////

// Sine wavetable
PROGMEM const unsigned char waveTable[256] = {
  128, 129, 131, 134, 137, 140, 143, 146, 149, 152, 155, 158, 161, 164, 167, 170, 
  173, 176, 179, 182, 185, 187, 190, 193, 195, 198, 201, 203, 206, 208, 210, 213, 
  215, 217, 219, 222, 224, 226, 228, 230, 231, 233, 235, 236, 238, 240, 241, 242, 
  244, 245, 246, 247, 248, 249, 250, 251, 251, 252, 253, 253, 254, 254, 254, 254,
  254, 255, 254, 254, 254, 254, 254, 253, 253, 252, 251, 251, 250, 249, 248, 247, 
  246, 245, 244, 242, 241, 240, 238, 236, 235, 233, 231, 230, 228, 226, 224, 222, 
  219, 217, 215, 213, 210, 208, 206, 203, 201, 198, 195, 193, 190, 187, 185, 182, 
  179, 176, 173, 170, 167, 164, 161, 158, 155, 152, 149, 146, 143, 140, 137, 134, 
  131, 128, 125, 122, 119, 116, 113, 110, 107, 104, 101,  98,  95,  92,  89,  86,  
  83,   80,  77,  74,  71,  69,  66,  63,  61,  58,  55,  53,  50,  48,  46,  43, 
  41,   39,  37,  34,  32,  30,  28,  26,  25,  23,  21,  20,  18,  16,  15,  14, 
  12,   11,  10,   9,   8,   7,   6,   5,   5,   4,   3,   3,   2,   2,   2,   2, 
  2,     1,   2,   2,   2,   2,   2,   3,   3,   4,   5,   5,   6,   7,   8,   9,
  10,   11,  12,  14,  15,  16,  18,  20,  21,  23,  25,  26,  28,  30,  32,  34, 
  37,   39,  41,  43,  46,  48,  50,  53,  55,  58,  61,  63,  66,  69,  71,  74, 
  77,   80,  83,  86,  89,  92,  95,  98, 101, 104, 107, 111, 114, 119, 123, 127
};

// Envelope wavetable
PROGMEM const unsigned char envelope[256]  = {
  255, 253, 250, 248, 245, 243, 240, 238, 235, 233, 230, 228, 226, 223, 221, 219,
  216, 214, 212, 210, 208, 205, 203, 201, 199, 197, 195, 193, 191, 189, 187, 185,
  183, 181, 179, 178, 176, 174, 172, 170, 168, 167, 165, 163, 161, 160, 158, 156,
  155, 153, 152, 150, 148, 147, 145, 144, 142, 141, 139, 138, 136, 135, 133, 132,
  130, 129, 128, 126, 125, 123, 122, 121, 119, 118, 117, 116, 114, 113, 112, 111,
  109, 108, 107, 106, 104, 103, 102, 101, 100,  99,  98,  96,  95,  94,  93,  92,
  91,   90,  89,  88,  87,  86,  85,  84,  83,  82,  81,  80,  79,  78,  77,  76,  
  75,   74,  73,  72,  71,  71,  70,  69,  68,  67,  66,  65,  64,  64,  63,  62,  
  61,   60,  60,  59,  58,  57,  57,  56,  55,  54,  54,  53,  52,  51,  51,  50,
  49,   49,  48,  47,  46,  46,  45,  45,  44,  43,  43,  42,  41,  41,  40,  40,
  39,   38,  38,  37,  37,  36,  35,  35,  34,  34,  33,  33,  32,  32,  31,  31,
  30,   30,  29,  29,  28,  28,  27,  27,  26,  26,  26,  25,  25,  24,  24,  23,
  23,   23,  22,  22,  21,  21,  21,  20,  20,  20,  19,  19,  19,  18,  18,  18,
  17,   17,  17,  16,  16,  16,  15,  15,  15,  15,  14,  14,  14,  13,  13,  13,
  13,   13,  12,  12,  12,  12,  11,  11,  11,  11,  11,  10,  10,  10,  10,  10,
  10,   9,   9,   9,   9,   9,   9,   9,   9,   8,   8,   8,   8,   8,   8,    8
};


const int incrementSpeed = 40;

boolean gateState;
boolean lastGateState;
boolean clock;
boolean lastClockState;
boolean playing;

int envelopeStartingPoint;
int envelopeIndex;
int waveTableIndex;
int sample;
int pos = 0;
int hitNumber;

long timer;
long tempo;

char pattern[16];

byte envelopeStartingPointTable[16]  = {
  170, 100, 170, 170, 
  100, 170, 170, 170, 
  170, 100, 170, 170, 
  100, 170, 170, 100
};


void GenerateEuclideanPattern (char *pattern, int hit, int steps) {
  int cur = steps;
  for (int i = 0; i < steps; i++) {
    *pattern = '.';
    if (cur >= steps) {
      cur -= steps;
      *pattern = 'x';
    }
    if (hit == 0) *pattern = '.';
    pattern++;
    cur += hit;
  }
}

void hitDrum() {
  playing = false;
  envelopeIndex = envelopeStartingPoint << 8;
  waveTableIndex = 0;
  playing = true;
}

void update()
{
  if (playing)
  {
    envelopeIndex += incrementSpeed;
    waveTableIndex += pgm_read_byte(&envelope[(envelopeIndex >> 8) & 0xff]);
    sample = pgm_read_byte(&waveTable[(waveTableIndex >> 4) & 0xff]);
    if (envelopeIndex > 0xff00) playing = false;
  }
  else if (sample) sample--; // Fade out
}

// Timer 0 interrupt routine
ISR(TIM0_COMPA_vect) {
  OCR1A = sample;
  update();
  if (timer == 0) clock = !clock;
  timer++;
  if (timer > tempo) timer = 0;
}

void setup() {
  pinMode(1, OUTPUT);                                      // Pin 6 (OC1A,PB1)
  TCCR0A = 0;                                              // TCCR0A (Timer/Counter Control Register A) reset
  TCCR0B = 0;                                              // TCCR0B (Timer/Counter Control Register B) reset
  TIMSK = 1 << OCIE0A;                                     // Set OCIE0A (Timer/Counter0 Output Compare Match A Interrupt Enable)
  TCCR0A = 1 << WGM00 | 1 << WGM01;                        // Fast PWM
  TCCR0B = 1 << WGM02 | 1 << CS02 | 0 << CS01 | 0 << CS00; // Fast PWM | CS02 set to have fClock/256 = 8000KHz / 256 = 31.250 KHz
  TCCR1  = 1 << PWM1A | 2 << COM1A0 | 1 << CS10;
}

void loop() {
  tempo = (1024 - analogRead(2)) * 30;
  hitNumber = map (analogRead(3), 0, 1023, 4, 13);
  if (hitNumber > 12) hitNumber = random (8, 12);
  envelopeStartingPoint = envelopeStartingPointTable[pos];
  GenerateEuclideanPattern((char *)&pattern, hitNumber, 16);

  if (clock != lastClockState ) {
    if (pattern[pos] == 'x') gateState = HIGH;
    else gateState = LOW;
    if (++pos >= 16) pos = 0;
    if (gateState == HIGH) hitDrum();
  }
  lastClockState = clock;
}





