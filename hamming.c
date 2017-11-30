#include <stdio.h>

unsigned char getByte(unsigned long word, int index)
{
  return ((word >> (index * 8)) & 255);
}

int addTable(unsigned char table[], int count, unsigned long codeWord)
{
  for (int index = 7; index >= 0; index--) 
    table[count++] = getByte(codeWord, index);
  return count;
}

int bit(unsigned char byte, int pos)
{
  return((byte & (1 << pos))? 1 : 0);
}

int hammingDistance(unsigned char a, unsigned char b)
{
  int distance = 0;
  for (int pos = 0; pos < 8; pos++)
    if (bit(a, pos) != bit(b, pos))
      distance++;
  return distance;
}
    

int main()
{
  int numCode; scanf("%d", &numCode);
  int numWord; scanf("%d", &numWord);
  int numText; scanf("%d", &numText);
#ifdef DEBUG
  printf("%d %d %d\n", numCode, numWord, numText);
#endif
  unsigned long codeWord;
  int count = 0;
  unsigned char codeTable[300];

  int leftover = numCode % 8; 
  for (int i = 0; i < numWord; i++) {
    scanf("%lu", &codeWord);
    if (leftover > 0 && i == numWord - 1) {
      for (int j = 0; j < leftover; j++)
	codeTable[count++] = getByte(codeWord, 7 - j);
    } else
      count = addTable(codeTable, count, codeWord);
  }
#ifdef DEBUG
  for (int i = 0; i < count; i++)
    printf("%hhu\n", codeTable[i]);
  printf("\n");
#endif
  unsigned char text;
  for (int i = 0; i < numText; i++) {
    scanf("%hhu", &text);
    for (int j = 0; j < count; j++)
      if (hammingDistance(text, codeTable[j]) <= 1) {
	  printf("%hhu\n", codeTable[j]);
	  break;
	}
  }
}
