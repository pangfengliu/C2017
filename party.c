#include <stdio.h>

#define AC

#ifdef AC
void getFriend(int friend[][256], int friendCount[], int friendship)
{
  for (int f = 0; f < friendship; f++) {
    int f1, f2;
    scanf("%d%d", &f1, &f2);
    friend[f1][friendCount[f1]++] = f2;
    friend[f2][friendCount[f2]++] = f1;
  }
}
#else
void getFriend(int friend[512][512], int friendship)
{
  for (int f = 0; f < friendship; f++) {
    int f1, f2;
    scanf("%d%d", &f1, &f2);
    friend[f1][f2] = 1;
    friend[f2][f1] = 1;
  }
}
#endif

#ifdef AC
  int friend[32768][256], friendCount[32768] = {0};
#else
  int friend[512][512] = {{0}};;
#endif

#ifdef AC 
void addFriend(int friend[][256], int friendCount[], int willGo[], int partyID)
{
  for (int i = 0; i < friendCount[partyID]; i++)
    willGo[friend[partyID][i]] = 1;
}
#else
void addFriend(int friend[][512], int willGo[], int partyID)
{
  for (int f = 0; f < 512; f++)
    if (friend[partyID][f] == 1)
      willGo[f] = 1;
}
#endif

int main()
{
  int F, friendship;
  scanf("%d%d", &F, &friendship);
#ifdef AC
  getFriend(friend, friendCount, friendship);
#else
  getFriend(friend, friendship);
#endif

  int willGo[32768] = {0};
  int partyID;
  while (scanf("%d", &partyID) == 1) {
#ifdef DEBUG
    printf("party student id %d\n", partyID);
#endif
    willGo[partyID] = 1;

    /* add friends */
#ifdef AC
    addFriend(friend, friendCount, willGo, partyID);
#else
    addFriend(friend, willGo, partyID);
#endif
  }

  for (int f = 0; f < F; f++)
    if (willGo[f] == 0)
      printf("%d\n", f);
}
