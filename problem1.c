#include <stdio.h>

int main()
{
  int ax, ay, bx, by, cx, cy;

  scanf("%d%d%d%d%d%d", &ax, &ay, &bx, &by, &cx, &cy);
#ifdef DEBUG
  printf("%d %d %d %d %d %d\n", ax, ay, bx, by, cx, cy);
#endif

  int dx = bx + cx - ax;
  int dy = by + cy - ay;

  int ex = ax + cx - bx;
  int ey = ay + cy - by;

  int fx = bx + ax - cx;
  int fy = by + ay - cy;

  printf("%d\n%d\n%d\n%d\n%d\n%d\n", dx, dy, ex, ey, fx, fy);

  return 0;
}
