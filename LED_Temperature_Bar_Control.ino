
// Function to on or off LEDs according to condition in ledTempBar

void ledWrite(int n){                                             // n = number of on LEDs

  for(int i=0; i<n ; i++) digitalWrite(i + led0, HIGH);           // turning on LEDs based on temperature
  for(int i=9; i>=n; i--) digitalWrite(i + led0, LOW);            // turning off remaining LEDs
}

// Condition creation function based on temperature read

void ledTempBar(float temp){ 
   analogWrite(pwmPin, 255);
   if(temp >= 20 && temp <= 30){
   // Bar graph indication based on temperature 

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
    // Running LED activates to indicate high temperature

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
   else if(temp < 20){
    // Breathing LED to indicate low temperature

   for(int i=0; i<=255; i= i+20) {
      currMills = millis();
      if((currMills - prevMills) >= PWMStepDelay){
        analogWrite(pwmPin, i);                                           
        for(int j=0; j<=9 ; j++) digitalWrite(j + led0, HIGH);           // turning on all LEDs at once
        prevMills = currMills;
      }
      // if millis difference condition is not satisfied need to stay in the same step. So reducing step size here and increasing in next interation (for condition)
      else i = i - 20;                                                                                                    
    } 
   for(int i=255; i>= 0; i= i-20){
      currMills = millis();
      if((currMills - prevMills) >= PWMStepDelay){
        analogWrite(pwmPin, i);
        prevMills = currMills;
      }
       // if millis difference condition is not satisfied need to stay in the same step. So increasing step size here and decreasing in next interation (for condition)
      else i = i + 20; 
    }
  }
}  