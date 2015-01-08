/* itoa(n,s,w). Converts int to string, field with w. 
   Must pad on left side */


#define BUFF_SIZE 100

#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
  char temp = *a;
  *a = *b;	
  *b = temp;
}

void reverse( char s[])
{
  int len = strlen(s);
  int i;
  for (i = 0; i < len/2; i++)
    swap( s+i, s+len-i-1);
}


void itoa(int n, char s[], int w)
{
  int isNegative, i, remainder;

  isNegative = n < 0;

  for (i = 0; n != 0; i++, n/=10, w--){
    
    if (isNegative)
      remainder = -(n%10);
    else
      remainder = n%10;

    s[i] = '0' + remainder;

  }
  
  
  if (isNegative){
    s[i++] = '-';
    w--;
  }

  while (w-- > 0){
    s[i++] = ' ';
  }

  s[i] = '\0';
  reverse(s); 
}

int main(int argc, char *argv[])
{
  char buff[BUFF_SIZE];
  if( argc != 3){
    printf("Wrong arguments: number width\n");
    return 1;
  }		

  int n = atoi(argv[1]);
  int w = atoi(argv[2]);

  if (w > BUFF_SIZE-1){
    printf("Width to big\n");
    return 1;
  }	

  printf("Input %d, width %d\n", n, w);
  itoa(n, buff, w);
  printf("output:\n%s\n", buff);

  return 0;
}

 
