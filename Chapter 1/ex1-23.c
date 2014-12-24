/* Removes all comments from input. */

#include <stdio.h>
#include <stdlib.h>


void removeSubstring(char* startPos, char *endPos);
int  findsubstr(char *str, char *substr);
void removeCommentsFromLine(char line[], int *commentIsActive);
size_t strlen(const char *s);

int main(int argc, char *argv[])
{
  char *line = NULL;
  size_t len = 0;

  int commentIsActive = 0;
	
  while (getline(&line, &len,  stdin) != EOF)
  {
    removeCommentsFromLine(line, &commentIsActive);
    
    printf("%s", line);
    free(line);
    line = NULL;
    len = 0;
  }
}

void removeCommentsFromLine( char line[], int * commentIsActive)
{
  int tempPos;	
	
  while (*line != '\0')
  {
		
    if (*commentIsActive == 1)
    {
      if ( (tempPos = findsubstr(line, "*/")) == -1)
      {
       	removeSubstring(line, line + (int)strlen((const char*)line));
	return;
      }
      else 
      {
	removeSubstring(line, &line[tempPos+2]);
	*commentIsActive = 0;
      }			
    } 
    else 
    {
      if ( (tempPos = findsubstr(line, "/*")) == -1)
	return;
      else 
      {			
	line += tempPos;
	*commentIsActive = 1;
      }
    }

  }

}

int findsubstr(char *str, char *substr)
{
  int i, j;

  for (i = 0; str[i] != '\0'; i++){
    j = 0;
    while (str[i+j] == substr[j] && str[i+j] != '\0')
      j++;
    if (substr[j] == '\0')
      return i;
  }
  return -1;
}

void removeSubstring(char* startPos, char *endPos)
{
  while (*endPos != '\0')
  {
    *startPos = *endPos;
    startPos++, endPos++;
  }
  
  *startPos = '\0';
}

size_t strlen(const char *s) 
{
  int n;
  for (n = 0; s[n] != '\0'; n++)
    ;
  return n;
}
