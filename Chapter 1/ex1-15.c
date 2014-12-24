/* Temperature conversion using a function 
   Prints table for fahr = 0, 20, ..., 300 */


#include <stdio.h>

float fahrToCelsius(float fahr);

int main( int argc, char *argv[])
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

  while (fahr <= upper)
  {
    printf("%3.0f %6.1f\n", fahr, fahrToCelsius(fahr));
    fahr += step;
  }

  return 0;
}

float fahrToCelsius(float fahr)
{
  return (5.0/9.0)*(fahr-32);
}
