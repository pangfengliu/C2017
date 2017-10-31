#include <stdio.h>
int fab(int n)
{
  return(fab(n - 1) + fab(n - 2));
}
int main()
{
  printf("%d\n", fab(3));
}
