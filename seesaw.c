#include <stdio.h>

int balance(int numbers[], int n)
{
  for (int support = 1; support < n - 1; support++) {
    int leftTorque = 0;
    for (int i = 0; i < support; i++)
      leftTorque += (support - i) * numbers[i];
    int rightTorque = 0;
    for (int i = support + 1; i < n; i++)
      rightTorque += (i - support) * numbers[i];

    if (leftTorque == rightTorque)
      return support;
  }
  return -1;
}

void printSeesaw(int numbers[], int n, int support)
{
  for (int i = 0; i < n; i++) {
    if (i == support)
      printf("v");
    else
      printf("%d", numbers[i]);

    if (i == n - 1)
      printf("\n");
    else
      printf(" ");
  }
}

void switchNumbers(int numbers[], int i, int n)
{
  int temp = numbers[i];
  numbers[i] = numbers[n - i - 1];
  numbers[n - i - 1] = temp;
}

int main()
{
  int n;
  scanf("%d", &n);
  int numbers[2048];
  for (int i = 0; i < n; i++)
    scanf("%d", &numbers[i]);

#ifdef OLDIMP
  int support = balance(numbers, n);
  if (support != -1) {
      printSeesaw(numbers, n, support);
      return 0;
  }
  for (int i = 0; i < n / 2; i++) {
    switchNumbers(numbers, i, n);
    int support = balance(numbers, n);
    if (support != -1) {
      printSeesaw(numbers, n, support);
      return 0;
    }
  }
#else
  int support;
  int i = 0;
  while ((support = balance(numbers, n)) == -1 && i < n/2) {
    switchNumbers(numbers, i, n);
    i++;
  }
  if (i == n/2)
    printf("no solution\n");
  else
    printSeesaw(numbers, n, support);
#endif
}
