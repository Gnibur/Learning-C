/* Function expand(s1, s2). Converts shorthand notation a-z to abc...xyz. 
   Should take both letters and digits. Should be case insensitive. 
   When a combination of characters and digits are given, the first type will be used.
   A leading or trailing - will be considered as "from start" or "to end" */

#include <stdio.h>
#include <ctype.h>

#define ALPHABET_LENGTH 26

/* s1 is input, s2 is output. s2 has to be provided, and has to be at least the length of the alphabet+1 */
void expand(char s1[], char *s2)
{
  /* find first character or digit or '-' */
  while ( !isdigit(*s1) && !isalpha(*s1) && *s1 != '-'){
    if (*s1 == '\0'){
      s2 = "Invalid input";
      return;
    }		
    s1++; 
  }
  
  char startChar = *s1;

  /* find end. Last occurrence of character or digit */
  char endChar;
  for (endChar = startChar; *s1 != '\0'; s1++){
  
    /* If start is specified, the string can end with a trailing '-' */
    if (*s1 == '-' && startChar != '-'){
      if (isdigit(startChar))
	endChar = '9';
      else 
	endChar = islower(startChar) ? 'z' : 'Z';
    }
    
    /* Else the last must be either a char or a digit */
    else if (isdigit(*s1) || isalpha(*s1))
      endChar = *s1;

  }      

  if (startChar == '-'){
    if (isdigit(endChar))
      startChar = '0';
    else
      startChar = islower(endChar) ? 'a' : 'A';
  }


  /* Fill array with result */
  int i;
  for ( i = 0; startChar+i != endChar; i++)
    s2[i] = startChar+i;
  s2[i] = endChar;
  s2[i+1] = '\0';
}	



int main( int argc, char *argv[])
{
  
  if (argc != 2){
    printf("Specify argument i.e 'a-z' or '0-9'\n");
    return 1;
  }
		
  char result[ALPHABET_LENGTH+1];

  expand(argv[1], result);
  printf("Result is: %s\n", result);	

  return 0;
}
