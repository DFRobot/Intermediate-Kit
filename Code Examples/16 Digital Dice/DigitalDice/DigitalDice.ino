//Item Thirteen- Digital Dice

int latchPin = 8; // Digital pin 8 shall be attached to the latch pin of chip 74HC595
int clockPin = 3; // Digital pin 3 shall be attached to the clock pin of chip 74HC595
int dataPin = 9; // Digital pin 9 shall be attached to the data pin of chip
int buttonPin = 2; // The button shall be attached to digital pin 2
// Number 0~9
byte Tab[] = { 0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
int number;
long randNumber;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  randomSeed(analogRead(0)); // set analog pin 0 to be a random seed
}

void loop() {
  randNumber = random(10); // result in a random number between 0 and 9
  showNumber(randNumber); // show that random number
  //Once a button has been pressed, a number will show up
  while (digitalRead(buttonPin) == HIGH) {
    delay(100);
  }
}

//This function is for the display
void showNumber(int number) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, Tab[number]);
  digitalWrite(latchPin, HIGH);
  delay(80);
}
