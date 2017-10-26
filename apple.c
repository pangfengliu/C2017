#include <stdio.h>

int main()
{
  int a, b;
  scanf("%d%d", &a, &b);
#ifdef DEBUG
  printf("%d %d\n", a, b);
#endif
  int level = b - a + 1;
  int total = (a + b) * level / 2;
  int side = a + b + 2 * level - 4;

  printf("%d\n%d\n", total, side); 
}
