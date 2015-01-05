/* Function lower written with the conditional operator. 
   Assumes that one uses the ASCII character set. */


#include <ctype.h>

int lower(char c)
{
  if (isalpha(c))
    return (c>='a' ? c : c+32);
  else 
    return c;
}


int main(int argc, char *argv[])
{
  if (argc != 2)
    return 1;
  else {
    putchar(lower(argv[1][0]));
    putchar('\n');
  }
  return 0;
}
