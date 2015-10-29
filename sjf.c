#include"assn5.h"
#include<stdio.h>
const int INT_MAX = 65536;
const int array_size = 100;
void
sjf (int count, int *sub, int *run)
{

  int clock = 0;
  int proc_left = count;
  int next_proc = 0;
  int ta = 0, wait = 0, resp = 0;
  int i = 0, j =0, index = 0 ;
  int k = 0;
  int queue_count=0;
  int next_clock, smallest;
  int queue[array_size];
  int time[array_size];
  int check =-1;
//queue[0]= sub[0];

//initilize array to -1
for (k = 0; k < array_size; k++)
{
queue[k]= check;
time[k]= check;
}

//loop through all processes
  while (proc_left < count)
    {

      if (queue_count == 0 && sub[next_proc] > clock)
	clock = sub[next_proc];

      while (clock >= sub[i])
	{
	  queue[i] = sub[i];
	  time[i] = run[i];
	  i++;
	  queue_count++;
	  next_proc++;
}

//sort
smallest = INT_MAX;
for (j = 0; j < array_size; j++) {
    if (time[j] != check && time[j] < smallest) {
        smallest = time[j];
        index = j;
}
}
//end sort



      resp += clock - sub[index];

      next_clock = clock + run[index];
      ta += next_clock - sub[index];
      wait += next_clock - sub[index] - run[index];

      clock = next_clock;

//reset varibles
queue_count--;

//      next_proc++;
    }

  printf ("Avg. Resp.:%.2f, Avg. T.A:%.2f, Avg. Wait:%.2f\n",
	  (float) resp / count, (float) ta / count, (float) wait / count);
}
