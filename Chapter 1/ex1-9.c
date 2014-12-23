/* Removes duplicates of blanks and prints out new text*/

#include <stdio.h>

int main(int argc, char *argv[])
{
  int c, blanks;

  blanks = 0;	

  while ( (c = getchar() ) != EOF)
  {
    if (c == ' ')
    {
      blanks++;
      if (blanks == 1)
	putchar(c);
    }
    else {
      putchar(c);
      blanks = 0;
    }
  }
  
  return 0;
}
