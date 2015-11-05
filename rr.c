//Primary author: Miranda Workman
//Assignment 5: CPU Scheduler Simulator
//Round Robin

/* Promise of Originality
I promise that this source code file has, in its entirety, been
written by myself or a member of my group and by no other person or
persons. If at any time an exact copy of this source code is found to
be used by another person outside my group in this term, I understand
that all members of my group and the members of the group that
submitted the copy will receive a zero on this assignment.
*/
#include"assn5.h"
#include<stdio.h>

void rr (int count, int *sub, int *run)
{
	int quantum = 100;
	int ready[count], rem_time[count], last_wait[count];
	int cur_proc = 0;
	int clock = sub[0];
	int next_clock = 0;
	int turnaround = 0, wait = 0, response = 0;
	int i = 0;
	int end = 0, round = 0;
	int fin_proc = 0;

	while ( fin_proc < count )
	{
        	//Check to see if there are "new" submissions
		while (sub[i] <= clock  && i < count)
	        {
			ready[end] = sub[i];
			rem_time[end] = run[i];
			last_wait[end] = 0;
			end = (end + 1) % count;
            		++i;
        	}
		//Push clock forward if necessary
		if (ready[cur_proc] < clock)
		{
			clock = ready[cur_proc];
		}

		//If the process is shorter than the quantum, it will complete and we don't need to worry about it any more.
		if (rem_time[cur_proc] <= quantum )
		{
			next_clock = clock + rem_time[cur_proc];
			++fin_proc;
			turnaround += next_clock - ready[cur_proc];
		}
		else
		{
			next_clock = clock + quantum;
			ready[end] = ready[cur_proc];
			rem_time[end] = rem_time[cur_proc] - quantum;
			last_wait[end] = next_clock;
			end = (end + 1) % count;
		}
		//Need this to somehow only increase the response time for the first time the process runs 
        	if (i < count)
		{
			response += clock - ready[cur_proc];
		}
		//Need wait to subtract the previous wait time--otherwise it'll count multiple times.
		wait += (clock - ready[cur_proc] - last_wait[cur_proc]);
		cur_proc = (cur_proc + 1) % count;
		clock = next_clock;
		round++;
	}
	printf("Round Robin with Time Quantum of %d\n", quantum);
	printf ("Avg. Resp.:%.2f, Avg. T.A:%.2f, Avg. Wait:%.2f\n",(float) response / count, (float) turnaround / count, (float) wait / count);
}
