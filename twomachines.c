#include <stdio.h>

int main()
{
  int Aready = 0, Bready = 0;
  int arrival, Atime, Btime;
  while (scanf("%d%d%d", &arrival, &Atime, &Btime) != EOF) {
    if (arrival > Aready)
      Aready = arrival;
    Aready += Atime;
    if (Aready > Bready)
      Bready = Aready;
    Bready += Btime; 
   printf("%d\n", Bready);
#ifdef DEBUG
    printf("%d %d %d", arrival, Atime, Btime);
#endif
  }
}
