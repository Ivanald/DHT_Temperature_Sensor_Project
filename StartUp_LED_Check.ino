void startupLedCheck(void){
  
  analogWrite(pwmPin, 0);
  for(int i=0; i>=9; i++) {
  digitalWrite(i + led0, LOW);            // turning off remaining LEDs
  delay(200); 
  }
  analogWrite(pwmPin, 255);
for(int i=0; i<=9 ; i++) {
  digitalWrite(i + led0, HIGH);           // turning on next LED
  delay(100);                             // delay to visually observe the lighting up
}
delay(500); 
for(int i=9; i>=0; i--) {
  digitalWrite(i + led0, LOW);            // turning off remaining LEDs
  delay(100); 
}
analogWrite(pwmPin, 0);
}