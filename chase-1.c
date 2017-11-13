#include <stdio.h>

void chasing(int **A[], int a, int *B[], int b, int C[], int c)
{
  for (int i = 0; i < a; i++)
    A[i] = NULL;
  for (int i = 0; i < b; i++)
    B[i] = NULL;
  char line[100];
  while (fgets(line, 100, stdin) != NULL) {
    printf("%s\n", line);
  }
}
