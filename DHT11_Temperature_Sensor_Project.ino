#include <Bonezegei_DHT11.h>

#include <Bonezegei_DHT11.h>

#include <Bonezegei_DHT11.h>

// Project: DHT Sensor Temperature and Humidty 
// Developer: Jahnavi 
// Date: 29/11/2024 Version 1
// End Date: 

// All Library files

#include <Bonezegei_DHT11.h>


// All definitions

#define dhtDataPin 2
#define led0 3
#define led1 4
#define led2 5
#define led3 6
#define led4 7
#define led5 8
#define led6 9
#define led7 10
#define led8 11
#define led9 12
#define blinkRate 250                               // Blinking rate of LED in milli seconds
#define sensorReadTime 1200                         // Time between each read of sensor

// All GlobalVariables

float temp = 0;                                     // For saving temp
int humidity = 0;                                   // For saving humidity
long int prevMills = 0, currMills = 0, prevRMills = 0, currRMills = 0;              // For mills function
bool toggle;                                        // For alternate blinking

// Instance creation

Bonezegei_DHT11 dht0(dhtDataPin);

void setup() {

  Serial.begin(9600);
  dht0.begin();

  // Pin Mode selection for all 10 leds

  for(int i = 0; i < 10; i++) pinMode(i + led0, OUTPUT);

}

// while loop for sensing continuously

void loop() {

currRMills = millis();
if((currRMills - prevRMills) >= sensorReadTime){
    dhtSensorRead();
    Serial.print("Temperature: ");
    Serial.println(temp);
    prevRMills = currRMills;
 }
ledTempBar(temp);
delay(1);
}

// Function to on or off LEDs according to condition in ledTempBar

void ledWrite(int n){                                             // n = number of on LEDs

  for(int i=0; i<n ; i++) digitalWrite(i + led0, HIGH);           // turning on LEDs based on temperature
  for(int i=9; i>=n; i--) digitalWrite(i + led0, LOW);            // turning off remaining LEDs
}

// Condition creation function based on temperature read

void ledTempBar(float temp){ 
   
   if(temp >= 20 && temp <= 30){

      if(temp <= 21) ledWrite(1);
      else if(temp <= 22) ledWrite(2);
      else if(temp <= 23) ledWrite(3);
      else if(temp <= 24) ledWrite(4);
      else if(temp <= 25) ledWrite(5);
      else if(temp <= 26) ledWrite(6);
      else if(temp <= 27) ledWrite(7);              
      else if(temp <= 28) ledWrite(8);
      else if(temp <= 29) ledWrite(9);
      else if(temp <= 30) ledWrite(10);    
   }
   else if(temp > 30){
     currMills = millis();
     if((currMills - prevMills) >= blinkRate){
      toggle = !toggle;
      for(int i = 0; i <= 8;  i = i+2 ){
        if(toggle){
          digitalWrite(i + led0, HIGH);                            // turning on even LEDs
          digitalWrite(i + led0 + 1, LOW);                         // turning off odd LEDs
        }
      else{
          digitalWrite(i + led0, LOW);                              // turning off even LEDs
          digitalWrite(i + led0 + 1, HIGH);                         // turning on odd LEDs
        }    
      } 
      prevMills = currMills;
    }
  }
}


