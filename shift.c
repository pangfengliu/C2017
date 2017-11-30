#include <stdio.h>

long long int MSB(long long int word, int T)
{
  return ((word >> (64 - T)) & ((((long long int)1) << T) - 1));
}

long long temp[1048576];

void shiftWord(long long int word[], int N, int numWordToShift)
{
  int numWord = N;
  for (int i = 0; i < numWord; i++)
    temp[(numWord + i - numWordToShift) % numWord] = word[i];
  for (int i = 0; i < numWord; i++)
    word[i] = temp[i];
}

void shiftBit(long long int word[], int N, int numBitToShift) 
{
  long long int shiftOut, shiftIn = MSB(word[0], numBitToShift);
  for (int i = N - 1; i >= 0; i--) {
    shiftOut = MSB(word[i], numBitToShift);
    word[i] <<= numBitToShift;
    word[i] |= shiftIn;
    shiftIn = shiftOut;
  }
}

void transmission(long long int word[], int N, int T)
{
  if (T == 0)
    return;
  else {
    shiftBit(word, N, T % 64);
    shiftWord(word, N, T / 64);
  }
}
