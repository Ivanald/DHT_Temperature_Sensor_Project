// Project: DHT Sensor Temperature and Humidty 
// Developer: Jahnavi 
// Date: 29/11/2024 Version 1
// End Date: 

// All Library files

#include <Bonezegei_DHT11.h>

// All definitions

#define dhtDataPin 2

// All GlobalVariables

float temp = 0;           // For saving temp
int humidity = 0;         // For saving humuduty

Bonezegei_DHT11 dht0(dhtDataPin);

void setup() {

  Serial.begin(9600);
  dht0.begin();

}

void loop() {

  dhtSensorRead();
  Serial.print("Temperature: ");
  Serial.println(temp);
  delay(1000);

}

