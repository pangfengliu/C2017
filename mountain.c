#include <stdio.h>

int main()
{
  int R, C;
  scanf("%d%d", &R, &C);
  for (int r = 0; r < R; r++)
    for (int c = 0; c < C; c++)
      scanf("%d", &map[r][c]);

  scanf("%d%d", &rowup, &colup);
  scanf("%d%d", &rowdown, &coldown);

  printf("%d%d\n", rowup, colup);
  printf("%d%d\n", rowdown, coldown);

}
