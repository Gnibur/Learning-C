/* Function setbits(x,p,n,y) 
   Returns x with the n bits that begin at position p set to the rightmost n bits of y, 
   leaving the other bits unchanged. 
   Position p is interpreted as position counted from LSD 
*/

#include <stdio.h>
#include <math.h>

int setbits(int x, int p, int n, int y)
{
  /* Temporary integer which has the n LSD set */
  int nBitsSet = pow(2, n) - 1;

  /* clear n bits from pos p in x */
  x &= ~(nBitsSet<<p);

  /* mask n bits in y */
  y &= nBitsSet;

  /* shift y to pos p */
  y = y<<p; 
	
  return x | y;
}

int getBit(int x, int p)
{
  return (x>>p) & 1;
}

void printBinary(int x)
{
  int i;
  for (i=31; i>=0; i--){
    printf("%d", getBit(x,i));
    if (i % 4 == 0)
      putchar(' ');
  }
  printf("\n");
}

int main(int argc, char *argv[])
{
  int x,p,n,y;
	
  if (argc != 5){
    printf("usage: x p n y\n");
    return 1;
  }

  x = atoi(argv[1]);
  p = atoi(argv[2]);
  n = atoi(argv[3]);
  y = atoi(argv[4]);

  printf("setbits with arguments x=%d, p=%d, n=%d, y=%d\n",x,p,n,y);
  printf("x before:\n");
  printBinary(x);
  printf("y before:\n");
  printBinary(y);

  x = setbits(x,p,n,y);
  printf("After set bits:\n");
  printBinary(x);
  return 0;
}



