#include <stdio.h>

/* This program counts blanks, tabs, and newlines */

int main(int argc, char *argv[])
{
  int blanks, tabs, newlines;
  char c; 

  blanks = 0;
  tabs = 0;
  newlines = 0;	

  while ( (c = getchar()) != EOF) 
  {
    if (c == ' ')
      blanks++;
    else if (c == '\t')
      tabs++;
    else if (c == '\n')
      newlines++;
  }

  printf("\nBlanks: \t%d\n"
	 "Tabs: \t%d\n"
	 "newlines: \t%d\n", blanks, tabs, newlines);

  return 0;
}
