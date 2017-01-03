/*
  Blinks a series of 8 green and 8 red lights
  Four of each are connected to p11,p6 (green) and p10,p5 (red)
 */



void setup() {
  
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}


void loop() {
  digitalWrite(5, HIGH);   // turn the LED on
  digitalWrite(10, HIGH); 
  digitalWrite(6, LOW);    
  digitalWrite(11, LOW);

  delay(600); 
 
  digitalWrite(5, LOW);   // turn the LED on
  digitalWrite(10, LOW);   
  digitalWrite(11, HIGH);
  digitalWrite(6, HIGH);
  
  
  delay(600);   
 
}
