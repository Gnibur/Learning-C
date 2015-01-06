/* binsearch */

#include <stdio.h> 

int binsearch(int x, int v[], int n)
{
  unsigned low, high, mid;

  low = 0;
  high = n - 1;
  
  /* Prevent loop-around */
  mid = low + (high-low)/2;

  while (v[mid] != x && low < high){
    if (x < v[mid])
      high = mid;
    else 
      low = mid + 1;
		
    mid = low + (high-low)/2;
  }

  if (v[mid] == x)
    return mid;
  else 
    return -1;
} 

int main(int argc, char *argv[])
{
  if (argc != 2){
    printf("Usage: searchval\n");
    return 1;
  }

  int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
  int pos = binsearch(atoi(argv[1]), arr, sizeof(arr)/sizeof(arr[0]));
  printf("Found at position %d\n", pos);

  return 0;
}
