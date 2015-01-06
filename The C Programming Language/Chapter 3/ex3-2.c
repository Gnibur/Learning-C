/* escape(s[],t,r) converts escape sequence to characters 
   and the other way around, depending on r.
   r = 1 converts char to string, r = 0 converts string to char. */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


void escape(char s[4], char *t, int r)
{

  if (r){ 
    /* convert char to string */

    s[0] = '\\';
    s[2] = '\0';

    char temp = *t;

    switch (*t){
    case '\a': s[1] = 'a'; break;
    case '\b': s[1] = 'b'; break;
    case '\f': s[1] = 'f'; break;
    case '\n': s[1] = 'n'; break;
    case '\r': s[1] = 'r'; break;
    case '\t': s[1] = 't'; break;	
    case '\v': s[1] = 'v'; break;
    case '\\': s[1] = '\\';break;
    case '\"': s[1] = '\"';break;
    case '\'': s[1] = '\'';break;
    
    default:
      s[0] = *t;
      s[1] = '\0';
      break;
    }
  } 
  else { 
    /* convert string to char */
    switch (s[1]){
    case 'a': *t = '\a'; break;
    case 'b': *t = '\b'; break;
    case 'f': *t = '\f'; break;
    case 'n': *t = '\n'; break;
    case 'r': *t = '\r'; break;
    case 't': *t = '\t'; break;	
    case 'v': *t = '\v'; break;
    case '\\':*t = '\\'; break;
    case '\"':*t = '\"'; break;
    case '\'':*t = '\''; break;

    default:
      printf("Error, escape sequence not recognized\n");
      *t = '\0';
      break;
    }
  }
} 

int main( int argc, char *argv[])
{

  if (argc != 3){
    printf("Usage: escape_sequence reverse\n");
    return 1;	
  }

  char str[4];
  strncpy(str, argv[1], 4);
  char c = str[0]; 
    
  if (atoi(argv[2]) == 1){
    escape(str, &c, 1);
    printf("Reversed char to string: %s\n", str);
  }
  else {
    escape(str, &c, 0);
    printf("Reversed string to char: %c\n", c);
  }

  return 0;
}






