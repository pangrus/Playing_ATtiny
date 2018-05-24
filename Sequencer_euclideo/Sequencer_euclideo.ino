//Sequencer  Euclideo
//Pangrus 2015 - 2018

byte colpi;
char pattern[16];
int pausa;
unsigned char stepCorrente = 0;

void setup() {
  pinMode (1, OUTPUT);
}

void RiempiPattern(char *pattern, byte colpi, byte lunghezzaPattern) {
  int cur = lunghezzaPattern;
  for (int i = 0; i < lunghezzaPattern; i++) {
    *pattern = '.';
    if (cur >= lunghezzaPattern) {
      cur -= lunghezzaPattern;
      *pattern = 'x';
    }
    if (colpi == 0) *pattern = '.';
    pattern++;
    cur += colpi;
  }
}

void loop() {
  colpi = map(analogRead(3), 0, 1023, 1, 16);
  pausa = 1023 - analogRead(2);

  RiempiPattern((char *)&pattern, colpi, 16);

  if (pattern[stepCorrente] == 'x') digitalWrite (1, HIGH);
  delay (50);

  digitalWrite (1, LOW);
  delay (pausa);

  if (++stepCorrente == 16) stepCorrente = 0;
}










