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
	int ready[count], rem_time[count], resubmit[count];
	int cur_proc = 0;
	int clock = sub[0];	//Start clock at first submission time
	int next_clock = 0;
	int turnaround = 0, wait = 0, response = 0;
	int i = 0;
	int end = 0;
	int fin_proc = 0;

	while ( fin_proc < count )
	{
		//If the current position is empty and the next submission time
		//is after the clock, push clock forward to that submission time
		if ( ready[cur_proc] < 0 && sub[i] > clock )
		{
			clock = sub[i];
		}
        	//Check to see if there are "new" submissions
		while (sub[i] <= clock  && i < count)
	        {
			ready[end] = sub[i];
			rem_time[end] = run[i];
			resubmit[end] = 0;
			end = (end + 1) % count;
            		++i;
        	}

		//If the process is shorter than the quantum, it will complete
		if (rem_time[cur_proc] <= quantum )
		{
			next_clock = clock + rem_time[cur_proc];
			++fin_proc;
			turnaround += next_clock - ready[cur_proc];
		}
		//If the process has remaining time, put it back in the ready queue
		//at position end. Set the "new submit time" to the next_clock.
		else
		{
			next_clock = clock + quantum;
			ready[end] = ready[cur_proc];
			rem_time[end] = rem_time[cur_proc] - quantum;
			resubmit[end] = next_clock;
			end = (end + 1) % count;
		}
		
		//If the process has not been resubmitted, increment the response time
		//Wait is the difference between when the process started running and
		//the submission time
        	if (resubmit[cur_proc] == 0)
		{
			response += clock - ready[cur_proc];
			wait += clock - ready[cur_proc];
		}
		//If the process has been run before, calculate wait: the difference
		//between when the process started running this time and when it was
		//put back in the ready queue. 
		else
			wait += clock - resubmit[cur_proc];
		//trace statements
		printf("clock =%d  ta:%d wait:%d response:%d\n", clock, turnaround, wait, response);

		//Remove "current" process from ready queue
		ready[cur_proc] = -1;
		rem_time[cur_proc] = -1;
		resubmit[cur_proc] = 0;

		cur_proc = (cur_proc + 1) % count;
		clock = next_clock;

	}
	printf("Round Robin with Time Quantum of %d\n", quantum);
	printf ("Avg. Resp.:%.2f, Avg. T.A:%.2f, Avg. Wait:%.2f\n",(float) response / count, (float) turnaround / count, (float) wait / count);
}
