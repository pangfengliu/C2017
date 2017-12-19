#include <stdio.h>

unsigned char mirror(unsigned char input)
{
  unsigned char output = 0;
  int left = 1 << 7;
  int right = 1;
  for (int i = 0; i < 8; i++, left >>= 1, right <<= 1)
    if (input & left)
      output |= right;
  return output;
}

int fileLength(FILE *fp)	/* needs rewinding after usage */
{
  fseek(fp, 0, SEEK_END);
  return(ftell(fp));
}

void shiftByte(unsigned char input, int offset, int length, int numByteToShift,
	       FILE *outputFile)
{
  fseek(outputFile, 
	(length + (length - offset - 1) - numByteToShift) % length, SEEK_SET);
  fwrite(&input, sizeof(unsigned char), 1, outputFile);
}

int main()
{
  char inputFileName[128];
  char outputFileName[128];
  int byteToShift;
  scanf("%s%s%d", inputFileName, outputFileName, &byteToShift);

  FILE *inputFile = fopen(inputFileName, "rb");
  FILE *outputFile = fopen(outputFileName, "wb");

  int inputFileLength = fileLength(inputFile);
  rewind(inputFile);		/* remember to do this */

  for (int i = 0; i < inputFileLength; i++) {
    unsigned char input;
    fread(&input, sizeof(unsigned char), 1, inputFile);
    shiftByte(mirror(input), i, inputFileLength, byteToShift, outputFile);
  }
  fclose(inputFile);
  fclose(outputFile);
}
