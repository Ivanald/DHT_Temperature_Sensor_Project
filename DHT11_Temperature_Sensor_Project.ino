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

// All GlobalVariables

float temp = 0;           // For saving temp
int humidity = 0;         // For saving humuduty

Bonezegei_DHT11 dht0(dhtDataPin);

void setup() {
  
  // Instance creation

  Serial.begin(9600);
  dht0.begin();
  // Pin Mode selection
  pinMode(led0, OUTPUT); 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
}

// while loop for sensing continuously

void loop() {

  dhtSensorRead();
  Serial.print("Temperature: ");
  Serial.println(temp);
  ledTempBar(temp);
  delay(1000);

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
}


