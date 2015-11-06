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


const int MAX_SIZE = 100;
void srtf(int count, int *sub, int *run)
{
	int remaining_process_times[100];
	int end_times[100];
	int current = 0;
	int x = 0;
	int time_left_current = 0;
	int time_left_others = 0;
	int elapsed = 0;
	int avg_wait_time = 0;
	int avg_response_time =0;
	int avg_turnaround_time=0;

	while (current < 4)
	{
		x = current;
		// Find how much time elapses between the start of the current and next processes
		elapsed = sub[current + 1] - sub[current];
		// If there is enough time to run the process to completion
		if (elapsed > run[current])
		{
			// Add zero to wait time because there was no waiting for this process
			avg_wait_time += 0;
			// There is no remaining time to process so fill this entry with zero
			remaining_process_times[current] = 0;
			// Store end times if the process for later calculations
			end_times[current] = sub[current] + run[current];
			// Track turnaround time by subtracting the ending time by the start time
			avg_turnaround_time += (end_times[current] - sub[current]);
			// See if there is extra time to finish previously preempted processes
			while (x > 0)
			{
				// If there is no remaining process time for this entry, move on
				if (remaining_process_times[x] == 0)
				{
					x = x-1;
				}
				else
				{
					// If there is time to finish a remaining process 
					if (elapsed - remaining_process_times[x] > 0)
					{
						avg_wait_time += end_times[x] - sub[x-1];
						// Indicaate process is finished
						remaining_process_times[x] = 0;
						avg_turnaround_time += end_times[x] - sub[x];
						x = x - 1;
					}
					// If there isn't time to finish a remaining process, do as much as possible
					else
					{
						remaining_process_times[x] = remaining_process_times[x] - elapsed;
						x = 0;
					}
				}
			}
		}
		// If the process doesn't have a shorter remaining time
		else
		{
		
			remaining_process_times[x] = run[x] - elapsed;
			avg_wait_time += run[x + 1];
		}
		current++;
	}
	printf("Shortest Remaining Time First\n");
	// Spit out some random numbers that I can't seem to fix no matter what I try
	printf("Avg. Resp.:%.2f, Avg. T.A:%.2f, Avg. Wait:%.2f\n",
		(float)avg_response_time/ count, (float)avg_turnaround_time / count, (float)avg_wait_time / count);
}