#include <stdio.h>

int bit(unsigned int word, int pos)
{
  return (word & (1 << pos)? 1 : 0);
}

int isOne(unsigned int word[], int r, int c, int C)
{
  int seq = r * C + c;
  int wordIndex = seq / 32;
  int pos = 31 - (seq % 32);
  return (bit(word[wordIndex], pos));
}

#define HASONE

int main()
{
  unsigned int word[1024];

  /* get R and C */
  int C; scanf("%d", &C);
  int R; scanf("%d", &R);

  /* get the chars for one and zero */
  char oneString[128]; 
  scanf("%s", oneString);
  char oneChar = oneString[0];

  char zeroString[128]; 
  scanf("%s", zeroString);
  char zeroChar = zeroString[0];
#ifdef DEBUG
  printf("%d %d %c %c\n", C, R, oneChar, zeroChar);
#endif
  /* get the words */
  int numWord = (R * C + 31) / 32; /* magic, do not modify */
  for (int i = 0; i < numWord; i++) {
    scanf("%u\n", &word[i]);
#ifdef DEBUG
    printf("%u\n", word[i]);
#endif
  }
#ifdef DEBUG
  /* unit test here */
  for (int i = 0; i < 32; i++)
    printf("%d\n", bit(2147483647, i));
#endif
#ifdef HASONE
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++){
      /* print the one char if it is 1, othersize print a zero */
      if (isOne(word, r, c, C))
	printf("%c", oneChar);
      else
	printf("%c", zeroChar);
    }
    printf("\n");
  }
#endif
}
