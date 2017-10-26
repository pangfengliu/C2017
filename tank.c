#include <stdio.h>

void printMap(int map[500][500], int R, int C)
{
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++)
      printf("%d", map[r][c]);
    printf("\n");
  }
}

int findObsCol(int map[500][500], int startR, int startC, int count) 
{
  int obstacle = 0;
  for (int r = startR; r < startR + count; r++)
    if (map[r][startC] == 2)
      obstacle++;

  return obstacle;
}

void setCol(int map[500][500], int startR, int startC, int count, int value) 
{
  for (int r = startR; r < startR + count; r++)
    map[r][startC] = value;
}


int findObsRow(int map[500][500], int startR, int startC, int count) 
{
  int obstacle = 0;
  for (int c = startC; c < startC + count; c++)
    if (map[startR][c] == 2)
      obstacle++;

  return obstacle;
}

void setRow(int map[500][500], int startR, int startC, int count, int value) 
{
  for (int c = startC; c < startC + count; c++)
    map[startR][c] = value;
}

int main()
{
  /* get the input */

  int R, C;
  scanf("%d%d", &R, &C);
  int tankR, tankC;
  scanf("%d%d", &tankR, &tankC);

  int map[500][500];
  for (int r = 0; r < R; r++)
    for (int c = 0; c < C; c++) {
      if (r < tankR && c < tankC)
	map[r][c] = 1;
      else
	map[r][c] = 0;
    }

  int obstacle;
  scanf("%d", &obstacle);
  for (int o = 0; o < obstacle; o++) {
    int row, col;
    scanf("%d%d", &col, &row);
    map[row][col] = 2;
  }
#ifdef DEBUG  
  printMap(map, R, C);
#endif
  /* process the commands */
  int command;
  int currentR = 0, currentC = 0;
  while (scanf("%d", &command) == 1) {
#ifdef DEBUG
    printf("command is %d\n", command);
#endif
    switch (command) {
    case 0:
      printMap(map, R, C);
      break;
    case 1:
      if (currentC + tankC < C) {
	if (findObsCol(map, currentR, currentC + tankC, tankR) <= 1) {
	  setCol(map, currentR, currentC + tankC, tankR, 1); 
	  setCol(map, currentR, currentC, tankR, 0); 
	  currentC++;
	}
      }
      break;

    case 3:
      if (currentC > 0) {
	if (findObsCol(map, currentR, currentC - 1, tankR) <= 1) {
	  setCol(map, currentR, currentC - 1, tankR, 1); 
	  setCol(map, currentR, currentC + tankC - 1, tankR, 0); 
	  currentC--;
	}
      }
      break;

    case 2:
      if (currentR + tankR < R) {
	if (findObsRow(map, currentR + tankR, currentC, tankC) <= 1) {
	  setRow(map, currentR + tankR, currentC, tankC, 1); 
	  setRow(map, currentR, currentC, tankC, 0); 
	  currentR++;
	}
      }
      break;

    case 4:
      if (currentR > 0) {
	if (findObsRow(map, currentR - 1, currentC, tankC) <= 1) {
	  setRow(map, currentR - 1, currentC, tankC, 1); 
	  setRow(map, currentR + tankR - 1, currentC, tankC, 0); 
	  currentR--;
	}
      }
      break;

    case 5:
      if (currentR > 0) {
	if (findObsRow(map, currentR - 1, currentC, tankC) <= 1) {
	  setRow(map, currentR - 1, currentC, tankC, 1); 
	  setRow(map, currentR + tankR - 1, currentC, tankC, 0); 
	  currentR--;
	}
      }
      break;


    }
  }
}
