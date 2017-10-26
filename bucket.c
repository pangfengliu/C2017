#include <stdio.h>
int main()
{
  int A, B, method;
  int ball;
  scanf("%d%d%d", &A, &B, &method);
  while (scanf("%d", &ball) == 1) {
    switch (method) {
    case 0:
      if (A >= ball)
	A -= ball;
      else if (B >= ball)
	B -= ball;
      break;
    case 1:
      if ((A <= B || B < ball) && A >= ball)
	A -= ball;
      else if (B >= ball)
	B -= ball;
      break;
    }
    printf("%d %d\n", A, B);
#ifdef DEBUG
    printf("%d\n", ball);
#endif
  }
}
