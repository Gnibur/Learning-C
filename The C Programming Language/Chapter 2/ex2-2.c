/* Write an equivalent to:
   
   for ( i = 0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
      s[i] = c;
   
   without using && or || */

#include <stdio.h>


#define LINE_LENGTH 100

int main(int argc, char *argv[])
{
  char s[LINE_LENGTH];

  int lim = LINE_LENGTH;
	
  int i;
  char c;
  for (i=0; i < lim-1; ++i){
    c = getchar();
    if (c == '\n')
      break;
    if ( c == EOF )
      break;
    s[i] = c;	
  }
  s[i]  = '\0';

  printf("%s\n", s);
	

  return 0;
}
