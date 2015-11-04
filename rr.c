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
	int queue[count], rem_time[count];
	int proc_left = count;
	int clock = 0;
	int cur_proc = 0;
	int turnaround = 0, wait = 0, response = 0;
	int next_clock = 0;
	int i = 0;
	int end = 0, round = 0;
	//Copy submission and run times into arrays that I can change
	for (i = 0; i < count; ++i)
	{
		queue[i] = sub[i];
		rem_time[i] = run[i];
	}

	while (proc_left > 0)
	{
		if (queue[cur_proc % count] > clock)
		{
			clock = queue[cur_proc];
		}
		if (round < count)
		{
			response += clock - queue[cur_proc];
		}
		wait += clock - queue[cur_proc];
		//If the process is shorter than the quantum, it will complete and we don't need to worry about it any more.
		if (rem_time[cur_proc] <= quantum )
		{
			next_clock = clock + rem_time[cur_proc];
			proc_left--;
			turnaround += clock - queue[cur_proc];
		}
		else
		{
			next_clock = clock + quantum;
			queue[ end % count ] = queue[cur_proc];
			rem_time[ end % count ] = rem_time[cur_proc] - quantum;
			++end;
		}
		cur_proc = (cur_proc + 1) % count;
		clock = next_clock;
		round++;
	}
	printf("Round Robin with Time Quantum of %d\n", quantum);
	printf ("Avg. Resp.:%.2f, Avg. T.A:%.2f, Avg. Wait:%.2f\n",(float) response / count, (float) turnaround / count, (float) wait / count);
}
