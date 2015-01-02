/* Program prints all input lines bigger than a specified 
   number of characters */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: length\n");
    return 1;
  }

  char *line = NULL;
  size_t len = 0;
  int charsRead;
 
  while ( (charsRead = getline(&line, &len, stdin)) != EOF)
  {
    if (charsRead > atoi(argv[1]))
      printf("%s",line);
    free(line);
    line = NULL;
    len = 0;
  }
  return 0;
}

