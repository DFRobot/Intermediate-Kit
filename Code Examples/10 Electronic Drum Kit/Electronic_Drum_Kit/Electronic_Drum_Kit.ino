// Electronic Drum Kit
int sensorPin = 0; //Piezo Disk Vibration Sensor V2 is to be attached to analog pin 0
int ledPin = 10; // Digital Piranha LED-R is to be attached to digital pin 10.
void setup() {
  pinMode(ledPin, OUTPUT);
}
void loop() {
  int sensorValue = analogRead(sensorPin); //collect value at analog pin 0
  // A value between 0 and 1023 to mapped to a value between 0 and 255
  int outputValue = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(ledPin, outputValue * 10); //write corresponding value for LED
  delay(10);
}
