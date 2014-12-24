/*	Fill tab with spaces */

#include <stdio.h>

int main(int argc, char *argv[])
{
  if (argc != 2){
    printf("Usage: tab_width\n");
    return 1;
  }

  int c, col, tabwidth;

  tabwidth = atoi(argv[1]);
  col = 0;

  while ( (c = getchar()) != EOF)
  {
    if ( c == '\t')
    {
      do {
	putchar(' ');
	col++;
      } while ( (col % tabwidth) != 0);
    }
    else if (c == '\n')
    {
      putchar(c);
      col = 0;
    }
    
    else 
    {
      putchar(c);
      col++;
    }
  }
  return 0; 
}
