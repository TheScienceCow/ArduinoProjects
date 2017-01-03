//***********************************************************************
//Functions to clear the values of the array registers
void clearreg_power()
{
  for(int i = 7; i >=  0; i--)
  {
     registers_power[i] = LOW;
  }
}

void clearreg_blue()
{
  for(int i = 7; i >=  0; i--)
  {
     registers_blue[i] = HIGH;
  }
   writereg_blue();
} 

void clearreg_red()
{
  for(int i= 7; i>=  0; i--)
  {
     registers_red[i] = HIGH;
  }
  writereg_red();
} 

void clearreg_green()
{
  for(int i= 7; i>=  0; i--)
  {
     registers_green[i] = HIGH;
  }
  writereg_green();
} 

//Function to write the values of the array registers to QA-QH
void writereg_power()
{
  digitalWrite(STCP_pin_power, LOW);
  for(int i = 7; i >=  0; i--)
  {
    digitalWrite(SHCP_pin_power, LOW);
    digitalWrite(DS_pin_power, registers_power[i] );
    digitalWrite(SHCP_pin_power, HIGH);
  }
  digitalWrite(STCP_pin_power, HIGH);
}

void writereg_blue()
{
  digitalWrite(STCP_pin_blue, LOW);
  for(int i = 7; i >=  0; i--)
  {
    digitalWrite(SHCP_pin_blue, LOW);
    digitalWrite(DS_pin_blue, registers_blue[i] );
    digitalWrite(SHCP_pin_blue, HIGH);
  }
  digitalWrite(STCP_pin_blue, HIGH);
}

void writereg_red()
{
  digitalWrite(STCP_pin_red, LOW);
  for (int i = 7; i>=0; i--)
  {
    digitalWrite(SHCP_pin_red, LOW);
    digitalWrite(DS_pin_red, registers_red[i] );
    digitalWrite(SHCP_pin_red, HIGH);
  }
  digitalWrite(STCP_pin_red, HIGH);
}

void writereg_green()
{
  digitalWrite(STCP_pin_green, LOW);
  for (int i = 7; i>=0; i--)
  {
    digitalWrite(SHCP_pin_green, LOW);
    digitalWrite(DS_pin_green, registers_green[i] );
    digitalWrite(SHCP_pin_green, HIGH);
  }
  digitalWrite(STCP_pin_green, HIGH);
}

//Function that decodes the array disp into three arrays, one for red, green, and blue
void disp_decode()
{
  for (int i = 0 ; i < 8 ; i++)
 {
   for (int j = 0 ; j < 8 ; j++)
   {
     if (disp[i][j]==1||disp[i][j]==4||disp[i][j]==6||disp[i][j]==7)
     {
       disp_blue[i][j] = 0;
     }
     else
     {
       disp_blue[i][j] = 1;
     }
     if (disp[i][j]==1||disp[i][j]==2||disp[i][j]==5||disp[i][j]==6)
     {
       disp_red[i][j] = 0;
     }
     else
     {
       disp_red[i][j] = 1;
     }
     if (disp[i][j]==1||disp[i][j]==3||disp[i][j]==5||disp[i][j]==7)
     {
       disp_green[i][j] = 0;
     }
     else
     {
       disp_green[i][j] = 1;
     }
   }
 } 
}
