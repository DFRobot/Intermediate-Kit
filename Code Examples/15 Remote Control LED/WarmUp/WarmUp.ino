//This code comes from IRrecvDemo under examples from the IRremote library
// ITEM TWELVE- IR Receiver

#include <IRremote.h> // include IRremote.h library
int RECV_PIN = 10; //define RECV_PIN (variable) to be 10
IRrecv irrecv(RECV_PIN); // Set RECV_PIN (pin11) as the IR receiver
decode_results results; // define results (variable) to be where results of the IR receiver is located

void setup() {
  Serial.begin(9600); //Set the baud rate to be 9600
  irrecv.enableIRIn(); //enable IR decoding
}

void loop() {
  if (irrecv.decode(&results)) { // if the decoding data has been received; store in results
    Serial.println(results.value, HEX); //Show the data in hexadecimals in the serial monitor
    irrecv.resume(); // wait to receive the next group of signals
  }
}
