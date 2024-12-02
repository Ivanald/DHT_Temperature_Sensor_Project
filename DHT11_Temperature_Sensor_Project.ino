
// Project: DHT Sensor Temperature and Humidty 
// Developer: Jahnavi 
// Date: 29/11/2024 Version 1
// End Date: 02/12/2024

// All Library files

#include <Bonezegei_DHT11.h>

// All definitions

#define dhtDataPin 2
#define pwmPin 3
#define led0 4
#define led1 5
#define led2 6
#define led3 7
#define led4 8
#define led5 9
#define led6 10
#define led7 11
#define led8 12
#define led9 13
#define blinkRate 250                               // Blinking rate of LED in milli seconds for temp > 30
#define sensorReadTime 1200                         // Time between each read of sensor
#define PWMStepDelay 100                            // Time between each PWM step for breathing LEDs
#define errorIndicatorDelay 150                     // Time between the blinking for error

// All GlobalVariables

float temp = 0;                                     // For saving temp
int humidity = 0;                                   // For saving humidity
long int prevMills = 0, currMills = 0,              // For mills function
         prevRMills = 0, currRMills = 0;        
bool toggle;                                        // For alternate blinking

// Instance creation

Bonezegei_DHT11 dht0(dhtDataPin);

void setup() {

  Serial.begin(9600);
  dht0.begin();
    
   // Pin Mode selection for all 10 leds

  for(int i = 0; i < 10; i++) pinMode(i + led0, OUTPUT);
  pinMode(pwmPin, OUTPUT);
  startupLedCheck();

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



