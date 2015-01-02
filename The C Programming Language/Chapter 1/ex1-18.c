/* Removes trailing blanks and tabs from lines,
   Removes empty lines */

#include <stdio.h>
#include <stdlib.h>

void cleanLine(char arr[]);

int main( int argc, char *argv[])
{
  char *line = NULL;
  size_t len = 0;

  while (getline(&line, &len, stdin) != EOF)
  {
    cleanLine(line);
    printf("%s", line);
    free(line);
    line = NULL;
    len = 0;
  }
  return 0;
}

void cleanLine(char arr[]){
  if (arr[0] == '\0' || arr[0] == '\n')
    return;
 
  /* find start */
  char *temp = arr;
  while (*temp == ' ' || *temp == '\t')
    temp++;
  
  /* move array such that the empty start is removed */
  int i = 0;
  while ((arr[i] = *temp++) != '\0')
    i++;
	
  /* remove end */
  i -= 1;  
  while (arr[i] == ' ' || arr[i] == '\t' || arr[i] == '\n')
    i--;

  arr[i+1]='\n';
  arr[i+2]='\0';
}
