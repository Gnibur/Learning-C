/* atof extended to accept scientic notation */ 
#include <stdio.h>
#include <string.h>
#include <math.h>

double atof(char s[])
{
  double val, power, exp;
  int i, sign;

  for (i = 0; isspace(s[i]); i++)
    ;

  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] -'0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++){
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
  }
  if (tolower(s[i]) == 'e') {
    i++;
    for (exp = 0.0; isdigit(s[i]); i++)
      exp = 10.0 * exp + (s[i] - '0');
  } else 
    exp = 1.0;

  return (sign * val / power) * pow(10,exp);
}


int main(int argc, char *argv[])
{
  if (argc != 2){
    printf("Usage: float\n");
    return 1;
  }

  printf("Number entered was %f\n", atof(argv[1]));
  return 0;
}


