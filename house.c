#include <stdio.h>
int main()
{
  int a[10];
  if (a == &a)
    printf("yes\n");
  else
    printf("no\n");

  if (a + 10 == &a + 1)
    printf("yes\n");
  else
    printf("no\n");

  printf("%p %p\n", a, &a);
  printf("%p %p\n", a, a + 10);
}
