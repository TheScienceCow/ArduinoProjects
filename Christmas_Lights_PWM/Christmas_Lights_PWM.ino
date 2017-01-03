/*
  Blinks a series of 8 green and 8 red lights
  Four of each are connected to p11,p6 (green) and p10,p5 (red)
 */


int count = 0;
boolean up_down=true;
void setup() {
  
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  
}


void loop() {
  analogWrite(5, count);   
  analogWrite(10, count); 
  analogWrite(6, 127-count);    
  analogWrite(11, 127-count);

  delay(10); 
 
  if (up_down)
  {
    count++;
  }
  else
  {
    count--;
  }
    
  if (count==127 || count==0)
  {
    up_down=!up_down;
  }

}
