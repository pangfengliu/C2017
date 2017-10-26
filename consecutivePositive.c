#include <stdio.h>

int main()
{
  int number;
  int currentLength = 0;
  int maxLength = 0;
  while (scanf("%d", &number) == 1) {
    if (number > 0) {
      currentLength++;
      if (currentLength > maxLength)
	maxLength = currentLength;
    } else
      currentLength = 0;
#ifdef DEBUG
    printf("%d %d\n", number, currentLength);
#endif
  }
  printf("%d\n", maxLength);
}
