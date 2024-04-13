#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int i, x, y;
  int **pptr = (int **)malloc(sizeof(int *) * 8);
  for (i = 0; i < 8; i++)
  {
    *(pptr + i) = (int *)malloc(sizeof(int) * 6);
  }
  for (x = 0; x < 8; x++)
  {
    for (y = 0; y < 6; y++)
    {
      *(*(pptr + x) + y) = 6 * x + y;
      
    }
  }
  for (x = 0; x < 8; x++)
  {
    for (y = 0; y < 6; y++)
    {
      printf("%3d", *(*(pptr + x) + y));
    }
    printf("\n");
  }
  for (x = 0; x < 8; x++)
  {
    free(*(pptr + x));
  }
  return 0;
}