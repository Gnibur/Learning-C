/* 	This program replaces each tab by \t,
	each backspace by \b, and each backslash by \\ */

#include <stdio.h>

int main(int argc, char *argv[])
{
  char c;

  while ( (c = getchar()) != EOF )
  {
    switch (c)
    {
    case '\t': putchar('\\'); putchar('t');
      break;
    case '\b': putchar('\\'); putchar('b');
      break;
    case '\\': putchar('\\'); putchar('\\');
      break;
    default:
      putchar(c);
    }
  }	

  return 0;
}
