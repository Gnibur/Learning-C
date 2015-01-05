/* x &= (x-1) deletes rightmost bit, in two's complement.
   This is because of that (x-1) will toggle the rightmost set bit and the following bits.
   The rightmost set bit and the following in x and x - 1 will therefore be complements.
   The & operator clears complements, which will clear the rightmost bit
*/
	 

#include <stdio.h>
#include <stdlib.h>

int bitcount(unsigned x)
{
  int b;
  for (b = 0; x != 0; x &= (x-1))
    b++;

  return b;
}

int main(int argc, char *argv[])
{
  if (argc != 2){
    printf("Usage: int\n");
    return 1;
  }

  unsigned d = atoi(argv[1]);

  printf("%d has %d bits set\n", d, bitcount(d));
  
  return 0;
  
}
