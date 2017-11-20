#include <stdio.h>

int bit(unsigned int word, int pos)
{
  return(word & (1 << pos)? 1 : 0);
}

int isOne(unsigned int word[], int r, int c, int C)
{
  int seq = r * C + c;
  int wordIndex = seq / 32;
  int pos = 31 - (seq % 32);
  return (bit(word[wordIndex], pos));
}

#define HASONEWORD

int main()
{
  /* get the row and column number */
  int C; scanf("%d", &C);
  int R; scanf("%d", &R);
  
  /* get the oen and zero char */
  char oneString[128], zeroString[128];
  scanf("%s%s", oneString, zeroString);
  char zero = zeroString[0];
  char one = oneString[0];
#ifdef DEBUG
  printf("%d %d %c %c\n", C, R, one, zero);
#endif
  /* get the words */
  int numBits = R * C;
  int numInt = (numBits + 31) / 32;

  unsigned int word[1024];
  for (int i = 0; i < numInt; i++) {
    scanf("%u", &(word[i]));
#ifdef DEBUG
    printf("%u\n", word[i]);
#endif
  }
#ifdef DEBUG
  unsigned int test = 2147483647;
  for (int i = 0; i < 31; i++)
    printf("%d\n", bit(test, i));
#endif
#ifdef HASONEWORD
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      /* if it is a zero print a zero char, else print a one char */
      if (isOne(word, r, c, C))
	printf("%c", one);
      else
	printf("%c", zero);
    }						
    printf("\n");
  }
#endif
}
