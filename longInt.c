#include <stdio.h>

int bit(unsigned long int word, int pos)
{
  return(word & (((unsigned long int)1) << pos)? 1 : 0);
}

int main()
{
  printf("%lu %lu %lu\n", sizeof(unsigned long long), sizeof(unsigned long int), sizeof(1));
  for (int i = 63; i >= 0; i--)
    printf("%d ", bit(2147483647000, i));

  printf("%d\n", 0737345672);
}
