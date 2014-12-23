/*	print Fahrenheit-Celsius table  */

#include <stdio.h>


int main(int argc, char *argv[])
{
  if (argc != 4)
  {
    printf("Usage: start stop step\n");
    return 1;
  }

  float fahr, celsius;
  int lower, upper, step;

  lower = atoi(argv[1]);
  upper = atoi(argv[2]);
  step = atoi(argv[3]);
	
  printf("Fahrenheit/Celsius table\n"
	 "Fahrenheit | Celsius\n"
	 "-------------------------------\n");
  fahr = lower;
  while (fahr <= upper)
  {
    celsius = (5.0/9.0) * (fahr-32.0);
    printf("%3.0f %13.1f\n", fahr, celsius);
    fahr += step;
  }
}
