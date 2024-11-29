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

  Serial.begin(9600);
  dht0.begin();
  
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

void loop() {

  dhtSensorRead();
  Serial.print("Temperature: ");
  Serial.println(temp);
  ledTempBar(temp);
  delay(1000);

  /*for(int i=0; i<10 ; i++){
   digitalWrite(i + led0, HIGH );
  delay(500);
  }
  //digitalWrite(led0, HIGH); */

}

void ledTempBar(float t){
   
   if(t>=20){
      if(t<= 21) digitalWrite(led0, HIGH);
      else if(t<=22){
              digitalWrite(led0, HIGH);
              digitalWrite(led1, HIGH);
   }
      else if(t<=23){
              digitalWrite(led0, HIGH);
              digitalWrite(led1, HIGH);
              digitalWrite(led2, HIGH);
              }
      else if(t<=24){
              digitalWrite(led0, HIGH);
              digitalWrite(led1, HIGH);
              digitalWrite(led2, HIGH);
              digitalWrite(led3, HIGH);
              }
      else if(t<=25){
              digitalWrite(led0, HIGH);
              digitalWrite(led1, HIGH);
              digitalWrite(led2, HIGH);
              digitalWrite(led3, HIGH);
              digitalWrite(led4, HIGH);
              }
      else if(t<=26){
              digitalWrite(led0, HIGH);
              digitalWrite(led1, HIGH);
              digitalWrite(led2, HIGH);
              digitalWrite(led3, HIGH);
              digitalWrite(led4, HIGH);
              digitalWrite(led5, HIGH);
              }
      else if(t<=27){
              digitalWrite(led0, HIGH);
              digitalWrite(led1, HIGH);
              digitalWrite(led2, HIGH);
              digitalWrite(led3, HIGH);
              digitalWrite(led4, HIGH);
              digitalWrite(led5, HIGH);
              digitalWrite(led6, HIGH);
              }
      else if(t<=28){
              digitalWrite(led0, HIGH);
              digitalWrite(led1, HIGH);
              digitalWrite(led2, HIGH);
              digitalWrite(led3, HIGH);
              digitalWrite(led4, HIGH);
              digitalWrite(led5, HIGH);
              digitalWrite(led6, HIGH);
              digitalWrite(led7, HIGH);
              }
      else if(t<=29){
              digitalWrite(led0, HIGH);
              digitalWrite(led1, HIGH);
              digitalWrite(led2, HIGH);
              digitalWrite(led3, HIGH);
              digitalWrite(led4, HIGH);
              digitalWrite(led5, HIGH);
              digitalWrite(led6, HIGH);
              digitalWrite(led7, HIGH);
              digitalWrite(led8, HIGH);
              }
     else if(t<=30){
              digitalWrite(led0, HIGH);
              digitalWrite(led1, HIGH);
              digitalWrite(led2, HIGH);
              digitalWrite(led3, HIGH);
              digitalWrite(led4, HIGH);
              digitalWrite(led5, HIGH);
              digitalWrite(led6, HIGH);
              digitalWrite(led7, HIGH);
              digitalWrite(led8, HIGH);
              digitalWrite(led9, HIGH);
              }
   }
}


