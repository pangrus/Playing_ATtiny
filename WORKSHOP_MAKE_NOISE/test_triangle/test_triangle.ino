int frequenza1;
int frequenza2;
volatile unsigned int Acc[]   = {0, 0, 0, 0};
volatile unsigned int Freqs[] = {0, 0, 0, 0};


void setup() {
   Serial.begin(9600);
}

void loop() {
byte Mask, Temp, Sum=0;
    Acc[0] = Acc[0] + 10;
    Serial.println ( Acc[0]);

    Sum = Sum + Acc[0]/256;
    Serial.println ( Sum);
 }

