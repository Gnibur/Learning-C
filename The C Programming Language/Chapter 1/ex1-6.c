/* Verify that the expression (getchar() != EOF) is 0 or 1 */

#include <stdio.h>

int main(int argc, char *argv[])
{
  int c, t;

  printf("Please enter a character not equal to EOF: ");

  
  /* Flush the input buffer, only save the first character */
  c = getchar();
  while ( (t = getchar()) != '\n')
    ;
  
  printf("getchar() != EOF evaluates to %d\n", c != EOF);
  
  
  printf("Please enter EOF, 'Ctrl-D': ");
  while ( (c = getchar()) != EOF)
    ;
  
  printf("\n(getchar() != EOF) evaluates to %d\n", c != EOF);

  return 0;
}
