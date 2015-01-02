/* Program prints a histogram of word lengths
   Words longer than MAX_WORD_LENGTH will be countes as MAX_WORD_LENGTH
 */

#include <stdio.h>

#define MAX_WORD_LENGTH 15

int main(int argc, char *argv[])
{
  int c, wordlength, blanks;
  int wordLengths[MAX_WORD_LENGTH] = {};

  blanks = 0;
  wordlength = 0;
  /* counting */
  while ( (c = getchar()) != EOF)
  {
    if (c == ' ' || c == '\t' || c == '\n')
    {
      blanks++;
      /* End of word */ 
      if (blanks == 1)
      {
	wordLengths[wordlength]++;
	wordlength = 0;
      }				
    }
    else 
    {
      if (wordlength < MAX_WORD_LENGTH - 1)
      {
	wordlength++;
	blanks = 0;
      }
    }
  }

  /* printing */
  int i;
  for (i = 0; i < MAX_WORD_LENGTH; i++)
  {
    printf("%2d: ",i+1);
    while (wordLengths[i] > 0)
    {
      putchar('*');
      wordLengths[i]--;
    }
    putchar('\n');
  }
	
	
  return 0;
}
