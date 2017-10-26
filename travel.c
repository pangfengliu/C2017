#include <stdio.h>


int inmap(int r, int c, int R, int C)
{
  return(r >= 0 && r < R && c >= 0 && c < C);
}

int Avisited[1024][1024] = {{0}};
int Bvisited[1024][1024] = {{0}};

void travel(int map[1024][1024], int N, int M, 
	    int arow, int acol, int brow, int bcol, 
	    int directionA[], int directionB[])
{
  int Astop = 0, Bstop = 0, step = 0;

  Avisited[arow][acol] = Bvisited[brow][bcol] = 1;

  while (Astop == 0 || Bstop == 0) {
    int drow[8] = {0, 0, 1, -1, 1, -1, -1, 1};
    int dcol[8] = {1, -1, 0, 0, 1, -1, 1, -1};
#ifdef DEBUG
    printf("%d %d %d %d %d\n", step, arow, acol, brow, bcol);
#endif
    /* up */

    if (Astop == 0) {
      int dir = -1, max = -1;
      for (int i = 0; i < 8; i++) {
	int newrow = arow + drow[i];
	int newcol = acol + dcol[i];
	if (inmap(newrow, newcol, N, M)) 
	  if (map[newrow][newcol] > map[arow][acol])
	    if (map[newrow][newcol] > max) {
	      dir = i;
	      max = map[newrow][newcol];
	    }
      }
      if (dir == -1) {
	directionA[step] = -1;
	Astop = 1;
      } else {
	directionA[step] = dir;
	arow += drow[dir];
	acol += dcol[dir];
	Avisited[arow][acol] = 1;
	if (Bvisited[arow][acol] == 1) {
	  Astop = 1;
	  directionA[step + 1] = -1;
	}
      }
    }
    
    /* down */
    if (Bstop == 0) {
      int dir = -1;
      int min = 100000000;
      for (int i = 0; i < 8; i++) {
	int newrow = brow + drow[i];
	int newcol = bcol + dcol[i];
	if (inmap(newrow, newcol, N, M)) 
	  if (map[newrow][newcol] < map[brow][bcol])
	    if (map[newrow][newcol] < min) {
	      dir = i;
	      min = map[newrow][newcol];
	    }
      }
      if (dir == -1) {
	directionB[step] = -1;
	Bstop = 1;
      } else {
	directionB[step] = dir;
	brow += drow[dir];
	bcol += dcol[dir];
	Bvisited[brow][bcol] = 1;
	if (Avisited[brow][bcol] == 1) {
	  Bstop = 1;
	  directionB[step + 1] = -1;
	}
      }
    }

#ifdef DEBUG
    printf("%d %d %d %d %d\n", step, arow, acol, brow, bcol);
#endif

    if (arow == brow && acol == bcol) {
      Astop = Bstop = 1;
      directionA[step + 1] = directionB[step + 1] = -1;
    }
    step++;
  }
}
