// Item Eight- Flame Alarm
float sinVal;
int toneVal;
void setup() {
  pinMode(8, OUTPUT); //Set up the buzzer’s pins
  Serial.begin(9600); // set the baud rate to be 9600 bps
}
void loop() {
  int sensorValue = analogRead(0); // The flame sensor is connected to analog pin 0.
  Serial.println(sensorValue);
  delay(1);
  if (sensorValue < 1023) { // If the sensor value is less than 1023, flame is detected and alarm is on
    for (int x = 0; x < 180; x++) { // transfer the sin function to radian
      sinVal = (sin(x * (3.1412 / 180))); // get the sound frequency with the sin function
      toneVal = 2000 + (int(sinVal * 1000)); //Give a tone to pin 8
      tone(8, toneVal);
      delay(2);
    }
  } else { // If the sensor value is greater than 1023, there is no flame and we turn the buzzer off
    noTone(8); // turn the buzzer off
  }
}
