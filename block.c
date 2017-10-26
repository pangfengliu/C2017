#include <stdio.h>

int main()
{
  int block;
  while (scanf("%d", &block) == 1) {
    int max = -1000000;
    int min = 10000000;
    int number;

    for (int i = 0; i < block; i++) {
    int incomplete = 0;
      int ret = scanf("%d", &number);
      if (ret == -1) {
	incomplete = 1;
	break;
      }
      if (number > max)
	max = number;
      if (number < min)
	min = number;
#ifdef DEBUG
      printf("%d\n", number);
#endif
    }
    if (incomplete) 
      printf("%d\n", min);
    else
      printf("%d\n", max);
  }
}
