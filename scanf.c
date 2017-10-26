#include <stdio.h>

int main()
{
  int ret, number;
  int array[100];
  while ((ret = scanf("%x", &number)) != EOF)
    printf("%d %d\n", ret, number);

  printf("%d\n", ret);
}
