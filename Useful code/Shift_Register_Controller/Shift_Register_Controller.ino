///////////////////////////////////
int DS_pin = 8; //SER pin 14 on the 75hc595
int STCP_pin = 9; //RCLK pin 12 on the 75hc595
int SHCP_pin = 10; //SRCLK pin 11 on the 75hc595

void setup()
{
  pinMode(DS_pin,OUTPUT);
  pinMode(STCP_pin,OUTPUT);
  pinMode(SHCP_pin,OUTPUT);
}

boolean registers[8];
//Function to clear the values of the array registers
void clearreg()
{
  for(int i= 7; i >= 0; i--)
  {
     registers[i] = LOW;
  }
} 
//Function to write the values of the array registers to QA-QH
void writereg()
{
  digitalWrite(STCP_pin, LOW);
  for (int i = 7; i >= 0; i--)
  {
    digitalWrite(SHCP_pin, LOW);
    digitalWrite(DS_pin, registers[i] );
    digitalWrite(SHCP_pin, HIGH);
  }
  digitalWrite(STCP_pin, HIGH);
}
//As an example, this loop sets a series of LEDs alternating between on and off
void loop()
{
  //Sets values
  registers[0] = LOW;
  registers[2] = LOW;
  registers[4] = LOW;
  registers[6] = LOW;

  registers[1] = HIGH;
  registers[3] = HIGH;
  registers[5] = HIGH;
  registers[7] = HIGH;
  //Writes values
  writereg();            
}
///////////////////////////////////
