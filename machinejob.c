#include <stdio.h>

int max(int a, int b) 
{
  return (a > b? a : b);
}

int main()
{
  int M, J;
  scanf("%d%d", &M, &J);

  int jobReady[500];
  int machineReady[500] = {0};
  int machine[500][500];
  int numTask[500];
  int time[500][500];
  int totalTask = 0;

  /* get the data */
  for (int j = 0; j < J; j++) {
    scanf("%d%d", &(jobReady[j]), &(numTask[j]));
    for (int t = 0; t < numTask[j]; t++) {
      scanf("%d%d", &(machine[j][t]), &(time[j][t]));
    }
    totalTask += numTask[j];
  }

#ifdef DEBUG
  for (int j = 0; j < J; j++) {
    printf("job %d\n", j);
    for (int t = 0; t < numTask[j]; t++)
      printf("machine %d time %d\n", machine[j][t], time[j][t]);
  }
  printf("There are %d tasks in total\n", totalTask); 
#endif

  int next[500] = {0};

  /* select the tasks to run */
  for (int t = 0; t < totalTask; t++) {
    /* select the next task to run */
    int earliestJob, earliestMachine;
    int earliest = 200000000;
    for (int j = 0; j < J; j++)
      if (next[j] < numTask[j]) {
	int m = machine[j][next[j]];
	int completion = max(machineReady[m], jobReady[j]) + 
	  time[j][next[j]];
	if (completion < earliest) {
	  earliestMachine = m;
	  earliestJob = j;
	  earliest = completion;
	}
      }
    /* update the information */

    machineReady[earliestMachine] = earliest;
    jobReady[earliestJob] = earliest;
    next[earliestJob]++;
  }  
      
  /* print the results */
  for (int j = 0; j < J; j++) 
    printf("%d\n", jobReady[j]);
}
