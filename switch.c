#include <stdio.h>
#include <string.h>

#define LINE 1000000

char string[10000000];
char *words[16384];
char **lines[1024];

char line[LINE];

int main()
{
  int L; scanf("%d\n", &L);
  int wcount[1024] = {0};
  char *strptr = string;
  char **wordsptr = words;
  for (int i = 0; i < L; i++) {
    fgets(line, LINE, stdin);
    lines[i] = wordsptr;
    wcount[i] = 0;
    char *ptr = strtok(line, " \t\n");
    while (ptr != NULL) {
      *wordsptr++ = strptr;
      wcount[i]++;
      strcpy(strptr, ptr);
      strptr += strlen(ptr) + 1;
      ptr = strtok(NULL, " \t\n");
    }
  }
  int C; scanf("%d\n", &C);
  for (int i = 0; i < C; i++) {
    int l1, l2, w1, w2;
    scanf("%d%d%d%d", &l1, &w1, &l2, &w2);
    char *temp =  lines[l1][w1];
    lines[l1][w1] = lines[l2][w2];
    lines[l2][w2] = temp;
  }
  for (int l = 0; l < L; l++) 
    for (int w = 0; w < wcount[l]; w++) 
      printf("%s%c", lines[l][w], (w == wcount[l] - 1)? '\n':' ');
}
