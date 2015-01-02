/* Program prints one word on each line */

#include <stdio.h>


int main(int argc, char *argv[])
{
  int c, blanks;

  blanks = 0;
  while ( ( c = getchar() ) != EOF )
  {
    if (c == ' ' || c == '\t' || c == '\n')
    {
      blanks++;		
      if (blanks == 1)
	putchar('\n');
    }
    else 
    {
      putchar(c);
      blanks = 0;
    } 

  }
	
  return 0;
}
