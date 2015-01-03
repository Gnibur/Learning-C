/* Find ranges of char, short, int and long, 
   signed and unsigned.
   Use information defined in <limits.h> and by direct computation.
   It is assumed that the numbers are represented using 2's complement.
*/

#include <limits.h>
#include <stdio.h>

int main( int argc, char *argv[] )
{
  /* by using definitions in headers */
  printf("Limits using header file\n");
  printf("Type\t\t\t\t  MIN\t\t\t   MAX\n");
  printf("---------------------------------------------------------------\n");

  printf("Signed   char  %22d\t%22d\n", SCHAR_MIN, SCHAR_MAX);
  printf("Unsigned char  %22u\t%22u\n", 0, UCHAR_MAX);

  printf("Signed   short %22d\t%22d\n", SHRT_MIN, SHRT_MAX);
  printf("Unsigned short %22u\t%22u\n", 0, USHRT_MAX);

  printf("Signed   int   %22d\t%22d\n", INT_MIN, INT_MAX);
  printf("Unsigned int   %22u\t%22u\n", 0, UINT_MAX);

  printf("Signed   long  %22li\t%22li\n", LONG_MIN, LONG_MAX);
  printf("Unsigned long  %22u\t%22lu\n", 0, ULONG_MAX);
  printf("\n\n");


  signed   char a = 0;
  unsigned char b = 0;

  signed   short c = 0;
  unsigned short d = 0;

  signed   int e = 0;
  unsigned int f = 0;

  signed   long g = 0;
  unsigned long h = 0;

  /* Finding limits by computing them. 
   * Negative numbers are representend with 2's complement. */

  printf("Limits using computation\n");
  printf("Type\t\t\t\t  MIN\t\t\t   MAX\n");
  printf("--------------------------------------------------------------\n");
	
  printf("Signed   char  %22d\t%22d\n", (signed char)(1<<8*sizeof(a)-1), 
	                                (unsigned char)~a>>1);
  printf("Unsigned char  %22d\t%22u\n", 0, (unsigned char)~b);

  printf("Signed   short %22d\t%22d\n", (signed short)(1<<8*sizeof(c)-1), 
	                                (unsigned short)~c>>1);
  printf("Unsigned short %22d\t%22u\n", 0, (unsigned short)~d);

  printf("Signed   int   %22d\t%22d\n", (signed int)(1<<8*sizeof(e)-1), 
	                                (unsigned int)~e>>1);
  printf("Unsigned int   %22u\t%22u\n", 0, (unsigned int)~f);

  printf("Signed   long  %22li\t%22li\n",(signed long)((long)1<<8*sizeof(g)-1), 
	                                 (unsigned long)~g>>1);
  printf("Unsigned long  %22d\t%22lu\n", 0, (unsigned long)~h);  	
       
  return 0;
}
