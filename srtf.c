//Primary Coder: Zachary Hall
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


void srtf(int count, int *sub, int *run)
{
	const int MAX_SIZE = 100;
	// Put start times and runs in two arrays.  Keep these arrays synced
	//int sub [MAX_SIZE] = sub;
	//int run [MAX_SIZE] = run;
	//int wait_queue[MAX_SIZE];
	int current = 0;
	int x = 0;
	int time_left_current = 0;
	int time_left_others = 0;
	int elapsed = 0;
	int avg_wait_time = 0;
	int avg_response_time =0;
	int avg_turnaround_time=0;
	// Calculate average wait time
	while (x < count)
	{
		// Find how much time has elapsed from the start of the current process to the introduction of the newest process
		elapsed = sub[current + 1] - sub[current];
		if (elapsed > run[current])
		{
			avg_wait_time += 0;
		}
		else
		{
			time_left_current = run[current] - elapsed;
			x = current + 1;
			while (time_left_current > 0)
			{
				elapsed = sub[x + 1] - sub[x];
				if (elapsed > run[x])
				{
					while (time_left_others > 0 && elapsed > run[x])
					{
						elapsed--;
						time_left_others--;
					}
					if (elapsed > run[x])
					{
						//elapsed = elapsed - run[x];
						time_left_current = time_left_current - elapsed;
					}
				}
				else
				{
					time_left_others = time_left_others + run[x] - elapsed;
				}
				avg_wait_time += run[x++];
			}

		}
		current++;

		
	}
	printf("Shortest Remaining Time First\n");
	printf("Avg. Resp.:%.2f, Avg. T.A:%.2f, Avg. Wait:%.2f\n",
		(float)avg_response_time/ count, (float)avg_turnaround_time / count, (float)avg_wait_time / count);
}