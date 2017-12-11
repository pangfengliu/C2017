#include "compute.h"
#include <string.h>
#include <stdio.h>

typedef struct {
  char *name;
  int numPapers;
  int numCitation;
} JournalInformation;

typedef struct {
  int numJournals;
  JournalInformation information[2000];
} IFTable;

void printIFTable(IFTable *iftable)
{
#ifdef DEBUG
  printf("%d journals in Table\n", iftable->numJournals);
#endif
  for (int i = 0; i < iftable->numJournals; i++)
    printf("%s %d/%d\n", iftable->information[i].name,
	   iftable->information[i].numCitation,
	   iftable->information[i].numPapers);
}


void addPaperIntoIFTable(IFTable *iftable, paper *p)
{
#ifdef DEBUG
  printf("paper has %s\n", p->journalName);
#endif
  for (int i = 0; i < iftable->numJournals; i++) {
#ifdef DEBUG
    printf("IFtable %d has %s\n", i, iftable->information[i].name);
#endif
    if (strcmp(p->journalName, iftable->information[i].name) == 0) {
      (iftable->information[i].numPapers)++;
      return;
    }
  }
  iftable->information[iftable->numJournals].name = p->journalName;
  iftable->information[iftable->numJournals].numPapers = 1;
  iftable->information[iftable->numJournals].numCitation = 0;
  (iftable->numJournals)++;
#ifdef DEBUG
  printIFTable(iftable);
#endif
}

int findJournalIndex(IFTable *iftable, char *name)
{
  for (int i = 0; i < iftable->numJournals; i++)
    if (strcmp(name, iftable->information[i].name) == 0)
      return i;
  return -1;
}

void addCitationIntoIFTable(IFTable *iftable, paper papers[], int index)
{
  for (int i = 0; i < papers[index].numCitedPaper; i++) {
    int jIndex = 
      findJournalIndex(iftable, papers[papers[index].citedPaperIndex[i]].journalName);
    (iftable->information[jIndex].numCitation)++;
  }
}


void sortIFTable(IFTable *iftable)
{
  JournalInformation *information = iftable->information;
  for (int i = iftable->numJournals - 2; i >= 0; i--)
    for (int j = 0; j <= i; j++) 
      if (strcmp(information[j].name, information[j + 1].name) > 0) {
	JournalInformation temp;
	temp = information[j];
	information[j] = information[j + 1];
	information[j + 1] = temp;
      }
}

void compute(paper papers[], int numPapers)
{						
  /* first compute the number of journals and the number of papers in each journal */
  IFTable iftable;
  iftable.numJournals = 0;

  for (int p = 0; p < numPapers; p++) 
    addPaperIntoIFTable(&iftable, &(papers[p]));
#ifdef DEBUG
  printIFTable(&iftable);
#endif
  /* then compute the number of citations for each journal */

  for (int p = 0; p < numPapers; p++) 
    addCitationIntoIFTable(&iftable, papers, p);
  
  sortIFTable(&iftable);
  printIFTable(&iftable);
}

