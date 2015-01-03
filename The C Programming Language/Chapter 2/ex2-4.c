/* Alternate version of squeeze
   Deletes all occurences of characters in s2 from s1. */

#include <stdio.h>

void squeeze(char s1[], char s2[])
{
  int i, j, k, containsChar;

  for (i = j = 0; s1[i] != '\0'; i++){
    containsChar = 0;
    for (k = 0; s2[k] != '\0'; k++)
      if (s1[i] == s2[k])
	containsChar = 1;
    if ( containsChar == 0 ) 
      s1[j++] = s1[i];
  }
  s1[j] = '\0';
}


int main( int argc, char *argv[])
{
  if (argc != 3){
    printf("Usage: Needs 2 arguments, s1 and s2\n");
    return 1;
  }

  squeeze(argv[1], argv[2]);
  printf("%s\n", argv[1]);
  return 0;
}
