#include <Servo.h>
int sensorPin = 3; // Digital Vibration Sensor-Digital 3
Servo myservo;
int pos = 0;
void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  myservo.attach(9); // Servo– Digital 9
}
void loop() {
  int sensorState = digitalRead(sensorPin); //Read state of the digital vibration sensor
  Serial.println(sensorState);
  if (!sensorState) { //If the state is 0, The servo moves 2° more but does not exceed 180°
    pos = pos + 2;
    if (pos >= 180) {
      pos = 180;
    }
    myservo.write(pos); //Write in rotation angle of the Servo
    Serial.println(pos); // Print rotation angle in serial port
    delay(100);
  } else { // Else, the servo moves 2° less but not less than 0°.
    pos = pos - 2;
    if (pos <= 0) {
      pos = 0;
    }
    myservo.write(pos);
    Serial.println(pos);
    delay(100);
  }
  delay(1);
}
