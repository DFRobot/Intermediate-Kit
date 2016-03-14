//Sample Code 9-1:

#include <dht11.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20, 16, 2); // Set LCD’s address to be 0x20. Let it display 2 lines with 16 characters per line
dht11 DHT;
#define DHT11_PIN 4

void setup() {
  lcd.init(); //LCD initial setup
  lcd.backlight(); // open LCD’s backlight
  Serial.begin(9600); // Set serial port’s baud rate to be 9600
  // serial port prints ”Type, status, Humidity(%), Temperature(C)”
  Serial.println("Type,\tstatus,\tHumidity(%),\tTemperature(C)");
  lcd.print("Humidity(%):"); //LCD screen prints ”Humidity(%):”
  lcd.setCursor(0, 1); //cursor to be moved to the first character in the 2nd line
  lcd.print("Temp(C):"); //LCD screen prints”Temp(C):”
}

void loop() {
  int chk; //for storage of data collected by DHT11 sensor
  Serial.print("DHT11, \t"); // read data collected by DHT11 sensor
  chk = DHT.read(DHT11_PIN);
  switch (chk) {
    case DHTLIB_OK:
      Serial.print("OK,\t");
      break;
    case DHTLIB_ERROR_CHECKSUM:
      Serial.print("Checksum error, \t");
      break;
    case DHTLIB_ERROR_TIMEOUT:
      Serial.print("Time out error, \t");
      break;
    default:
      Serial.print("Unknown error, \t");
      break;
  }

  // serial port shows temperature and humidity
  Serial.print(DHT.humidity, 1);
  Serial.print(",\t");
  Serial.println(DHT.temperature, 1);
  //LCD screen prints temperature and humidity
  lcd.setCursor(12, 0);
  lcd.print(DHT.humidity, 1);
  lcd.setCursor(8, 1);
  lcd.print(DHT.temperature, 1);
  delay(1000);
}
