void clear_all()
{
  for (int i = 0 ; i < 8 ; i++)
 {
    for (int j = 0 ; j < 8 ; j++)
   {
     if (disp[i][j] != 0)
     {
       disp[i][j] = 0;
     }
    } 
 } 
}

