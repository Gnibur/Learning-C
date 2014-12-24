/* Reverses input lines */

#include <stdio.h>
#include <stdlib.h>

void reverse(char line[], int length);
void swap(char *a, char *b);

int main(int argc, char *argv[])
{
  char *line = NULL;
  size_t size = 0;
  int length;

  while ( (length = getline(&line, &size, stdin)) != EOF)
  {
    reverse(line, length-1); /* don't reverse newline character */
    printf("%s",line);
    free(line);
    line = 0;
    size = 0;
  }
  return 0;
}

void reverse(char line[], int length)
{
	char* end = line+length-1;
	char* start = line;

	while (start < end)
	{
		swap(start, end);
		start++; end--;
	}	
}

void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}
