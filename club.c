#include <stdio.h>
#include <stdlib.h>

int disjoint(unsigned long int a, unsigned long int b)
{
  return ((a & b) == 0);
}

void printClub(int club[], int num)
{
  for (int i = 0; i < num; i++)
    printf("%d\n", club[i]);
}

int findDisjointSet(int club, int numClub,
		    unsigned long int clubMember[], 
		    unsigned long int peopleSelected,
		    int numClubSelected,
		    int numClubToSelect, 
		    int clubSelected[]) /* return 1 if a solution vsn be found */
{
  if (numClubSelected == numClubToSelect) {
    printClub(clubSelected, numClubToSelect);
    return 1;
  }
  if (club >= numClub)
    return 0;
  if (disjoint(peopleSelected, clubMember[club])) {
    /* to select */
    clubSelected[numClubSelected] = club;
    if (findDisjointSet(club + 1, numClub, clubMember, 
			peopleSelected | clubMember[club], 
			numClubSelected + 1, numClubToSelect, clubSelected))
      return 1;
  }
  /* not to select */
  return findDisjointSet(club + 1, numClub, clubMember, peopleSelected, 
			 numClubSelected, numClubToSelect, clubSelected);
}

int main()
{
  int numClub; scanf("%d", &numClub);
  int numClubToSelect; scanf("%d", &numClubToSelect);

  unsigned long int clubMember[200] = {0};
  for (int club = 0; club < numClub; club++) {
    int numMember; scanf("%d", &numMember);
    int index;
    for (int m = 0; m < numMember; m++) {
      scanf("%d", &index);
      clubMember[club] |= (((unsigned long int)1) << index);
    }
  }
  int clubSelected[200];
  findDisjointSet(0, numClub, clubMember, 0, 0, numClubToSelect, clubSelected);
}
