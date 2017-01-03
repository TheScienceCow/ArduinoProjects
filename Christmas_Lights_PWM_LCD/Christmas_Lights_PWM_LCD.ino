#include <LiquidCrystal.h>

/*
  Alternately pulses 8 green and 8 red LEDs
  Four of each are connected to pin10, pin6 (green) and pin9, pin5 (red), all PWM I/O connections
  LCD:
  Register Select is pin12
  Enable is pin11
  Data4 is pin8
  Data5 is pin7
  Data6 is pin4
  Data7 is pin3
 */
//Defining lcd
LiquidCrystal lcd(12, 11, 8, 7, 4, 3);
//Counter used for PWM
int count = 0;
//Bool for whether the light is getting brighter or dimmer
boolean up_down=true;

void setup() 
{
  //Pin setup
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  //Setup for 16x2 matrix
  lcd.begin(16, 2);
  //Printing text
  lcd.print("Merry Christmas!");
  //Set cursor to next line
  lcd.setCursor(0,1);
  //Printing text
  lcd.print("Happy Holidays!");
}

void loop() 
{
  //Writing to the green LEDs
  analogWrite(5, count);   
  analogWrite(9, count);
  //Writing to the red LEDs with opposing LED brightness 
  analogWrite(6, 100-count);    
  analogWrite(10, 100-count);
  //Delay of 10ms per adjustment of LED brightness
  delay(10); 
  //Logic for determining LED brightness
  if (up_down)
  {
    count++;
  }
  else
  {
    count--;
  }
  if (count==100 || count==0)
  {
    up_down=!up_down;
  }
}
