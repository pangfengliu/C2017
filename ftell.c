#include <stdio.h>
#include <assert.h>

int main()
{
  FILE *fp = fopen("ftell.c", "r");
  assert(fp != NULL);
  fseek(fp, 0, SEEK_END);
  printf("%ld\n", ftell(fp));
}
