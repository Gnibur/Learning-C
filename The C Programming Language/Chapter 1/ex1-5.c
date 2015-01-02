/* Modified temperature conversion program. 
   Converts in reverse order */

#include <stdio.h>


int main(int argc, char *argv[])
{
  if (argc != 4)
  {
    printf("Usage: start stop step\n");
    return 1;
  }
  
  float fahr, celsius;
  int start, stop, step;	
  
  start = atoi(argv[1]);
  stop = atoi(argv[2]);
  step = atoi(argv[3]);

  printf("Fahrenheit/Celsius table\n"
	 "Fahrenheid | Celsius\n"
	 "-------------------------------\n");
  fahr = start;
  while (fahr >= stop)
  {
    celsius = (5.0/9.0) * (fahr-32.0);
    printf("%3.0f %13.1f\n", fahr, celsius);
    fahr -= step;
  }



}

