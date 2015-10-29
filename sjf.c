//Primary Coder: Cody Kellogg	
//Group project
//CS 3060-601 Fall 2015
//Assignment #5
/* Promise of Originality
I promise that this source code file has, in it's entirety, been
written by myself and by no other person or persons. If at any time an
exact copy of this source code is found to be used by another person in
this term, I understand that both myself and the student that submitted
the copy will receive a zero on this assignment.
*/
 
#include"assn5.h"
#include<stdio.h>
const int INT_MAX = 650000;
const int array_size = 100;
const int check = -1;

void sjf (int count, int *sub, int *run)
{
  int clock = 0;
  int proc_left = 0;
  int next_proc = 0;
  int ta = 0, wait = 0, resp = 0;
  int i = 0, j = 0, index = 0;
  int k = 0;
  int queue_count = 0;
  int next_clock, smallest;
  int queue[array_size];
  int time[array_size];

//initilize array to -1
  for (k = 0; k < array_size; k++)
    {
      queue[k] = check;
      time[k] = check;
    }

//loop through all processes
  while (proc_left < count)
    {

      if (queue_count == 0 && sub[next_proc] > clock)
	{
	  clock = sub[next_proc];
//              printf ("reset clock to %d: \n",clock );
	}

      while (clock >= sub[i] && next_proc < count)
	{
	  queue[i] = sub[i];
	  time[i] = run[i];
	  i++;
	  queue_count++;
	  next_proc++;
	}

//sort
      smallest = INT_MAX;
      for (j = 0; j < array_size; j++)
	{
	  if (time[j] != check && time[j] < smallest)
	    {
	      smallest = time[j];
	      index = j;
	    }
	}
//end sort

      resp += clock - queue[index];

      next_clock = clock + time[index];
      ta += next_clock - queue[index];
      wait += next_clock - queue[index] - time[index];

      clock = next_clock;
//printf ("%d: %d :%.2f, %.2f, %.2f\n",index, next_proc,(float) resp / proc_left, (float) ta / proc_left, (float) wait / proc_left); 
//printf ("%d: %d :%.2f, %.2f, %.2f\n",index, next_proc,(float) resp , (float) ta , (float) wait);

//reset varibles
      queue_count--;
      proc_left++;
      queue[index] = check;
      time[index] = check;
    }

  printf ("Shortest Job First\n");
  printf ("Avg. Resp.:%.2f, Avg. T.A:%.2f, Avg. Wait:%.2f\n",
	  (float) resp / count, (float) ta / count, (float) wait / count);
}
