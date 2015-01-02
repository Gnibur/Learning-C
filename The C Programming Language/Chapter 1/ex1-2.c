/* Ex1-2. Experiment to find out what happens when printf's argument
string contains '\c', where c is some character not listed above */

#include <stdio.h>

int main(int argc, char *argv[])
{
  printf("Printing unknown escape sequence: \c\n");
  return 0;
}

/* Compiler(gcc) gives warning: unknown escape sequence '\c' 
   Program output gives the character 'c' */
