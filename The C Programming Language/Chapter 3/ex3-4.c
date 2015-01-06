/* itoa. Also handles the most negative number. 
   Given solution does not handle the most negative number when using two's complement because of n = -n, which inverts to the positive number. In two's complement, there is one more negative number than posivite numbers(not counting 0). 
*/

#include <stdio.h>

#define BUFF_SIZE 100


size_t strlen(const char *s)
{
  int i;
  for (i = 0; s[i] != '\0'; i++)
    ;
  return i;
}

void swap(char *a, char *b)
{
  char temp = *a;
  *a = *b;	
  *b = temp;
}

void reverse(char s[])
{
  int len = strlen(s);
  int i;
  for (i = 0; i < len/2; i++)
    swap( s+i, s+len-i-1);
}

void itoa(int n, char s[])
{
  if (n == 0){
    s[0] = '0';
    s[1] = '\0';
    return;
  }

  int i;
  for (i=0; n != 0; i++, n/=10){
    if (n < 0)
      s[i] = '0' - (n%10);
    else
      s[i] = '0' + (n%10);
  }

  if (n < 0)
    s[i++] = '-';

  s[i] = '\0';
  reverse(s); 
}

int main(int argc, char *argv[])
{
  if( argc != 2){
    printf("Wrong arguments, one number\n");
    return 1;
  }	

  char buff[BUFF_SIZE];
	
  int n = atoi(argv[1]);
  printf("Input %d\n", n);
  itoa(n, buff);
  printf("output: %s\n", buff);

  return 0;
}
