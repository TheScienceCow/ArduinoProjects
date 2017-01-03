//Determining how the display array gets changed
void column_update()
{
  disp_decode();
  clearreg_power();
  clearreg_blue();
  clearreg_red();
  clearreg_green();
  selected_column++;
  if (selected_column==8)
  {
    selected_column=0;
  }
  
  registers_power[selected_column] = HIGH; 
  for (int i = 0 ; i < 8 ; i++)
  {
    registers_blue[i] = disp_blue[selected_column][i];
    registers_red[i] = disp_red[selected_column][i];
    registers_green[i] = disp_green[selected_column][i];
  }
  
  writereg_power();
  writereg_blue();
  writereg_red();
  writereg_green();
}
