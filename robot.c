#include <stdio.h>

int main()
{
  int X, Y;
  scanf("%d%d", &X, &Y);
  int command;
  int x = 0, y = 0;
  printf("%d\n%d\n", x, y);
  while (scanf("%d", &command) != EOF) {
    int newx = x;
    int newy = y;
    int r = command % 5;
    int valid = 1;
    switch (r) {
    case 0:
      valid = 0;
      break;
    case 1: 
      newx += command;
      if (newx >= X)
	valid = 0;
      break;
    case 2: 
      newx -= command;
      if (newx < 0)
	valid = 0;
      break;
    case 3: 
      newy += command;
      if (newy >= Y)
	valid = 0;
      break;
    case 4: 
      newy -= command;
      if (newy < 0)
	valid = 0;
      break;
    }
    if (valid) {
      x = newx;
      y = newy;
      printf("%d\n%d\n", x, y);
    }
  }
}
