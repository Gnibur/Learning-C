/* Prints the length of the line, 
   and as much as possible of the line  */

#include <stdio.h>


#define MAX_LENGTH 20

/* Reads a line with a maximum length.
   Includes the newline character
   Returns the correct length of the line. */
int getlineLimited(char line[], int maxLength);

int main(int argc, char *argv[])
{
  int length;
  char line[MAX_LENGTH];

  while ( (length = getline2(line, MAX_LENGTH)) ){
      printf("Line length: %d, line: %s\n", length, line);
  }

}

int getline2(char line[], int maxLength){
  int i, c;
  
  i = 0;
  while ( (c = getchar()) != EOF)
  {
    if (i < maxLength - 1)
      line[i] = c;
    i++;
    
    if (c == '\n')
      break;
  }
 
  if (i >= maxLength)
    line[maxLength-1] = '\0';
  else 
    line[i] = '\0';

  return i;
}
