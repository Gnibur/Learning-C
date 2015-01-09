/* strrindex(char s[], char t[])
   Returns the rightmost index of t in s. If not found it returns -1.
*/

#include <stdio.h>

int strrindex(char s[], char t[])
{
  int i, j, pos;
	
  pos = -1;
  for (i = 0; s[i] != '\0'; i++){
    for (j = 0; s[i+j] == t[j]; j++){
      if (s[i+j] == '\0' || t[j] == '\0')
	break;
    }	
    if (t[j] == '\0')
      pos = i;
  }	
  return pos;
}

int main( int argc, char *argv[])
{
	
  if (argc != 3){
    printf("Usage: string pattern\n");
    return -1;
  }

  int pos = strrindex(argv[1], argv[2]);
  if ( pos != -1)
    printf("String \"%s\" was found in \"%s\" at position %d\n", argv[2], argv[1],pos);
  else 
    printf("String \"%s\" was not found in \"%s\"\n",argv[2], argv[2]);

  return 0;
}



