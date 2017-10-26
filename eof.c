#include <stdio.h>

int main()
{
  int a, b, c;
  while ((c = scanf("%d%d", &a, &b))) {
    printf("%d %d %d\n", a, b, c);
  }
}
