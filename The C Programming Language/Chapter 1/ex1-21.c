/* entab. Replace spaces with tabs. */

#include <stdio.h>
#include <stdlib.h>

int countSpacesFromPos(char *line, int pos);

int main( int argc, char *argv[])
{
  if (argc != 2){
    printf("Usage: tab_width\n");
    return 1;
  }

  char *line = NULL;
  size_t size = 0;
  int col, tabwidth, i, nSpaces, positionsToNextTab;

  tabwidth = atoi(argv[1]);
 
  while ( getline(&line, &size, stdin) != EOF)
  {
    col = 0;
    for (i = 0; line[i] != '\0'; i++)
    {
      if (line[i] == ' ')
      {

	nSpaces = countSpacesFromPos(line, i);
	positionsToNextTab = tabwidth - (col % tabwidth);

	if ( nSpaces < positionsToNextTab || nSpaces == 1)
	{
	  /* Not possible to insert tab*/
	  putchar(' ');
	  col++;
	}
	else
	{
	  putchar('\t');
	  /* ignore next spaces  */
	  while (--positionsToNextTab > 0)
	    i++;

	  col += positionsToNextTab+1;
	}
      
      }

      else 
      { 
	putchar(line[i]);
	col++;
      }
    }
    free(line);
    line = NULL;
    size = 0;
  }

  return 0;
}


int countSpacesFromPos(char *line, int pos){
  int n = 0;
  while (line[pos + n] == ' ')
    n++;
  return n;
}
