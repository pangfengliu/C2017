#include <stdio.h>

int **first[200];
int *second[1000000];

int ***constructTable(int A[], int B[])
{
  int *Bptr = B;  
  int ***firstPtr = first;
  int **secondPtr = second;

  for (int i = 0; A[i] != 0; i++) {
    *firstPtr++ = secondPtr;
    for (int j = 0; j < A[i]; j++) {
      printf("j is %d\n", j);
      while (*Bptr != 0) {
	*secondPtr++ = Bptr;
	printf("%d\n", *Bptr);
	Bptr++;
      }
      Bptr++;			/* skip 0 */
    }
    *secondPtr++ = NULL;
#ifdef DEBUG
    printf("%d\n", A[i]);
#endif
  }
  *firstPtr = NULL;
  return first;
}
