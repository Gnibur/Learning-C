/* prints a celsius to fahrenheid */

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
	 "Celsius | Fahrenheid\n"
	 "-------------------------------\n");
  celsius = lower;
  while (celsius <= upper)
  {
    fahr = (9.0/5.0)*celsius+32.0;
    printf("%3.0f %10.1f\n", celsius, fahr);
    celsius += step;
  }
}
