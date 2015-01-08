/* itob(n,s,b). Converts integer n to string s containing integer with base b.
   Handles all bases from 2 to 10+26(digits + characters).
   Uses simple sign notatation, all bases show sign, and therefore the result is not in two's complement form.
*/

#define BUFF_SIZE 100

#include <stdio.h>
#include <string.h>

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


void itob(int n, char s[], int b){
  int isNegative, i, remainder;
    
  isNegative = n < 0;
  for (i = 0; n != 0; i++, n /= b){

    if (isNegative)
      remainder = -(n % b);
    else
      remainder = n % b;

    if (remainder < 10)
      s[i] = '0' + remainder;
    else /* also use characters in representation */ 
      s[i] = 'A' - 10 + remainder;
  }	

  if (isNegative)
    s[i++] = '-';

  s[i] = '\0';
  reverse(s); 
} 

int main(int argc, char *argv[])
{
  char buff[BUFF_SIZE];

  if( argc != 3){
    printf("Wrong arguments: number base\n");
    return 1;
  }
		
  int n = atoi(argv[1]);
  int b = atoi(argv[2]);

  printf("Input %d, base %d\n", n, b);

  itob(n, buff, b);
  printf("output: %s\n", buff);

  return 0;
}


