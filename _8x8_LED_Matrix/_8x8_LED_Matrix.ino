#include <MsTimer2.h>
#include <TimerOne.h>
//Pin assignments
//power = column
//colours = rows
int DS_pin_power = 5; //SER pin 14 on the 75hc595
int STCP_pin_power = 6; //RCLK pin 12 on the 75hc595
int SHCP_pin_power = 7; //SRCLK pin 11 on the 75hc595

int DS_pin_blue = 8; //pin 14 on the 75hc595
int STCP_pin_blue = 9; //pin 12 on the 75hc595
int SHCP_pin_blue = 10; //pin 11 on the 75hc595

int DS_pin_red = 2; //pin 14 on the 75hc595
int STCP_pin_red = 3; //pin 12 on the 75hc595
int SHCP_pin_red = 4; //pin 11 on the 75hc595

int DS_pin_green = 11; //pin 14 on the 75hc595
int STCP_pin_green = 12; //pin 12 on the 75hc595
int SHCP_pin_green = 13; //pin 11 on the 75hc595

//Registers to hold the values of each colour for a column
boolean registers_power[8];
boolean registers_blue[8];
boolean registers_red[8];
boolean registers_green[8];
//An array to control what gets displayed
//Off    0
//White  1
//Red    2    
//Green  3
//Blue   4
//Yellow 5
//Purple 6
//Teal   7
int disp [8][8] = {0};
int disp_blue [8][8] = {0};
int disp_green [8][8] = {0};
int disp_red [8][8] = {0};
//Current column being displayed
int selected_column = 0;

int counter;
int del = 10000;
int flag=0;
int i=0;
//***********************************************************************
void setup()
{
  //Setting pins as outputs
  pinMode(DS_pin_power,OUTPUT);
  pinMode(STCP_pin_power,OUTPUT);
  pinMode(SHCP_pin_power,OUTPUT);
  pinMode(DS_pin_blue,OUTPUT);
  pinMode(STCP_pin_blue,OUTPUT);
  pinMode(SHCP_pin_blue,OUTPUT);
  pinMode(DS_pin_red,OUTPUT);
  pinMode(STCP_pin_red,OUTPUT);
  pinMode(SHCP_pin_red,OUTPUT);
  pinMode(DS_pin_green,OUTPUT);
  pinMode(STCP_pin_green,OUTPUT);
  pinMode(SHCP_pin_green,OUTPUT);
  //Clearing initial values of the shift registers just in case
  clearreg_power();
  clearreg_blue();
  clearreg_green();

  disp_decode();
  
  Timer1.initialize(1); //Timer interrupt every 10us
  Timer1.attachInterrupt(column_update);
  
  counter=del;

  MsTimer2::set(1,update);
  MsTimer2::start();
}
int analogPinh = A5;     
int valh = 0;
int analogPinv = A4;     
int valv = 0;
void loop()
{
  valv = analogRead(analogPinv); 
  valh = analogRead(analogPinh);
}

void update()
{
//  clear_all();
//  disp[0][i] = 1;
//  i++;
//  if (i==8)
//  {
//    i=0;
//  }
   clear_all();
  if (valv > 1024-256)
  {
    disp[2][1] = 1;
  }
  else if (valv < 256)
  {
    disp[0][1] = 1;
  }
  
  if (valh > 1024-256)
  {
    disp[1][2] = 1;
  }
  else if (valh < 256)
  {
    disp[1][0] = 1;
  }
  
}
//***********************************************************************
