/* rightrot(x,n). Rotates x n bits to the right. */

#include <stdio.h>
#include <math.h>


int getBit(int x, int p)
{
  return (x>>p)&1;
}
void printBinary(int x)
{
  int i;
  for (i=31; i>=0; i--){
    printf("%d", getBit(x,i));
    if (i%4 == 0)
      putchar(' ');
  }
  printf("\n");
}

int main(int argc, char *argv[])
{
  if (argc != 3){
    printf("Usage: x n\n");
    return 1;
  }

  unsigned x = atoi(argv[1]);
  unsigned n = atoi(argv[2]);
	
  printf("Before:\n");
  printBinary(x);


  /* Has the n LSB set */
  int nBitsSet = pow(2,n)-1;

  int shiftedOut = x & nBitsSet;
  x = x>>n;	
  x = x | (shiftedOut<<(32-n));

  printf("After:\n");
  printBinary(x);

  return 0;
}

