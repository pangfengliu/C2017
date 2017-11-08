#include <stdio.h>
#include <string.h>

int main()
{
  char target[1024];
  scanf("%s", target);
  char command[1024];
  while (scanf("%s", command) == 1) {
#ifdef DEBUG
    printf("%s\n", command);
#endif
    if (command[0] == 'p') 
      printf("%s\n", target);
    else {
      char delimiter = command[1];
      int alength = strchr(command + 2, delimiter) - command - 2;
      int blength = strlen(command) - 4 - alength;
      char a[1024], b[1024];
      strncpy(a, command + 2, alength);
      a[alength] = '\0';
      strncpy(b, command + 3 + alength, blength);
      b[blength] = '\0';

      char *ptr = strstr(target, a);
      if (ptr != NULL) {
	char newTarget[1024];
	int prefixLen = ptr - target;
	strncpy(newTarget, target, prefixLen);
	newTarget[prefixLen] = '\0';
	strcat(newTarget, b);
	strcat(newTarget, target + prefixLen + strlen(a));
	strcpy(target, newTarget);
      }
    }
  }
}
