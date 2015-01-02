// Line folder, long lines are split
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int nextPossibleLineBreak(char *line, int startPos, int maxLineLength);

int main(int argc, char *argv[])
{	

  if (argc != 2)
  {
    printf("Usage: line_length\n");
    return 1;
  }

  char *line = NULL;
  size_t size = 0;
  int bytesRead, maxLineLength, i, lastSpacePos, col;

  maxLineLength = atoi(argv[1]);

  while ( (bytesRead = getline(&line, &size, stdin)) != EOF )
  {
    if (bytesRead < maxLineLength)
      printf("%s", line);
    else 
    {
      
      for (i = 0, col = 0; line[i] != '\n'; i++, col++)
      {

	/* Check for suitable line break */
	if (line[i]==' ')
	{
	  if (nextPossibleLineBreak(line, i+1, maxLineLength) >= maxLineLength)
	  {
	    putchar('\n');
	    col = 0;
	    i++;
	  }
	}

	/* Not possible to make nice line break, split word */
	if ( col == maxLineLength - 1){
	  putchar('-');
	  putchar('\n');
	  col = 0;
	}
	
	putchar(line[i]);
      }
      putchar('\n');

    }
    free(line);
    line = 0;
    size = 0;
  }

  return 0;	
}

int nextPossibleLineBreak(char *line, int startPos, int maxLineLength)
{
  int i;
  for (i = startPos; line[i] != '\0'; i++)
    if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
      break;

  return i;
}
