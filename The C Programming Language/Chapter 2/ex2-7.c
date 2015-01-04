/* Function invert. 
   Returns x with the n bits thath begin at position p inverted. 
   The others remain unchanged. */

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
  if (argc != 4){
    printf("Usage: x p n\n");
    return 1;
  }	
	
  int x = atoi(argv[1]);
  int p = atoi(argv[2]);
  int n = atoi(argv[3]);

  printf("Before:\n");
  printBinary(x);

  printf("After\n");

  /* pow(2,n)-1 returns a value which has the n LSB set.*/
  int nBitsSet = pow(2,n)-1;

  /* XOR with 1 inverts the bits. */
  x ^= nBitsSet<<p;
  printBinary(x);	

  return 0;
}



