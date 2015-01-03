/* strpbrk. Function any returns the first location in
   s1 where any character from s2 occurs */


#include <stdio.h>

int any(char s1[], char s2[])
{
  int i,j;
	
  for (i = 0; s1[i] != '\0'; i++)
    for (j = 0; s2[j] != '\0'; j++)
      if (s1[i] == s2[j])
	return i;

  return -1;
}

int main( int argc, char *argv[])
{
  if (argc != 3){
    printf("Expects 2 arguments\n");
    return 1;
  }

  printf("First occurence was on pos %d\n", any(argv[1], argv[2]));

  return 0;
}
