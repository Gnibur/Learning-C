/* htoi(s), converts a string of hexadecimal digits to int.
   String can optionally include 0x or 0X. 
   Both upper and lower case letters are allowed. 
   Returns -1 if input is invalid. */

#include <stdio.h>
#include <ctype.h>

/* Converts the character to an int. Assumes the character is valid */
int hexcharToInt(char c)
{
  if (isalpha(c))
    return (10+toupper(c)-'A');
  else 
    return (toupper(c)-'0');
}

/* Returns 1 if the character is a valid hex character. */
int isHexChar(char c)
{
  if ( c>='0' && c<='9'
       || toupper(c)>='A' && toupper(c)<='F')
    return 1;
  else 
    return 0;
}

int htoi(const char *hexString)
{
  int i, result;
  i = 0; 
  result = 0;

  /* Ignore leading whitespaces */
  while (hexString[i] == ' ')
    i++;


  /* Check if string starts with 0x */
  if (hexString[i] != '\0')
    if (hexString[i] == '0' && tolower(hexString[i+1]) == 'x')
      i += 2;

  /* Start conversion. Each character shifts result 4 bits */
  for ( ; hexString[i] != '\0'; i++){
    if (isHexChar(hexString[i]))
      result = (result<<4) | hexcharToInt(hexString[i]);
    else 
      return -1;
  }

  return result;
}


int main(int argc, char *argv[])
{
  if (argc < 2){
    printf("Expects 1 argument on hexadecimal form\n");
    return 1;
  }

  printf("Input: %s\n"
	 "Output: %d\n", argv[1], htoi(argv[1]));
  return 0;
}


