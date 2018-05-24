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
  pinMode (outputPin, OUTPUT);
}

void loop () {
  int parameter1 = (analogRead(controlPin1)/64) + 1; 
  int parameter2 = (analogRead(controlPin2)/128) + 1;
  output = (t>>parameter1|t|t>>(t>>parameter1))*parameter2;;
  analogWrite (outputPin, output);
  t++;
}


