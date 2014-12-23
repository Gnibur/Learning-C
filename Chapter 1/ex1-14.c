/* Program prints histogram of character frequency*/


#include <stdio.h>

#define NO_OF_CHARACTERS 26

int main(int argc, char *argv[])
{
  char c, charcount[NO_OF_CHARACTERS]={};
	
  // count characters
  while ( (c = getchar()) != EOF )
  {
    if (c >= 'a' && c <= 'z')
      charcount[c-'a']++;
    else if (c >= 'A' && c <= 'Z')
      charcount[c-'A']++; 
  }	

  // print histogram
  int i;	
  printf("Histogram of characters\n");
  for (i = 0; i < NO_OF_CHARACTERS; i++)
  {
    printf("%c: ",i+'A');
    while (charcount[i] > 0)
    {
      putchar('*');
      charcount[i]--;
    }
    putchar('\n');
  }

  return 0;
}
