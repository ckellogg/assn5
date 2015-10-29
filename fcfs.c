//Code writer: Cody Kellogg / Instructor
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


void fcfs (int count, int *sub, int *run)
{

  int clock = 0;
//int proc_left = count;
  int next_proc = 0;
  int ta = 0, wait = 0, resp = 0;
  int next_clock;
  while (next_proc < count)
    {

      if (sub[next_proc] > clock)
	clock = sub[next_proc];

      resp += clock - sub[next_proc];

      next_clock = clock + run[next_proc];
      ta += next_clock - sub[next_proc];
      wait += next_clock - sub[next_proc] - run[next_proc];

      clock = next_clock;
      next_proc++;


    }

  printf ("First Come, First Serve\n");
  printf ("Avg. Resp.:%.2f, Avg. T.A:%.2f, Avg. Wait:%.2f\n",(float) resp / count, (float) ta / count, (float) wait / count);
}
