#include <IRremote.h>
int RECV_PIN = 10;
int ledPin = 3; // LED – digital 3
boolean ledState = LOW; // ledstate for storage of LED’s state
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(ledPin, OUTPUT); // set LED to be in the output mode
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    // Once the code for the power button has been received
    //turn the mode of LED from HIGH to LOW or the other way.
    if (results.value == 0xFD00FF) {
      ledState = !ledState; // reverse it
      digitalWrite(ledPin, ledState); // Change the state of LED
    }
    irrecv.resume();
  }
}
