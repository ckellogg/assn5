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
	int ready[count], rem_time[count];
	int index = 0;
	int clock = 0;
	int next_clock = 0;
	int turnaround = 0, wait = 0, response = 0;
	int i = 0;
	int end = 0;
	int size = 0;
	int fin_proc = 0;

	while ( fin_proc < count )
	{
		//If there aren't any processes currently ready, push clock forward until the next submission time
		if ( size == 0 && sub[i] > clock )
		{
			clock = sub[i];
		}
        	//Check for new submissions
		while (sub[i] <= clock  && i < count)
	        {
			ready[end] = i;
			rem_time[i] = run[i];
			printf("Process %d added. ready=%d, time=%d\n", i, index, rem_time[i]);
			++size;
			end = (end + 1) % count;
            		++i;
        	}

		//If remaining time is the same as the total run time, increase the response counter
		if (rem_time[ready[index]] == run[ready[index]])
			response += clock - sub[ready[index]];

//		printf("current process=%d ready[curproc]=%d rem_time[curproc]=%d\n", cur_proc, ready[cur_proc], rem_time[cur_proc] );
		//If the process is shorter than the quantum, it will complete
		if (rem_time[ready[index]] <= quantum )
		{
			next_clock = clock + rem_time[ready[index]];
			++fin_proc;
			size--;
			turnaround += next_clock - sub[ready[index]];
			wait += next_clock - sub[ready[index]] - run[ready[index]];
			printf("Process %d finished at %d\n", ready[index], clock);
		}
		//If the process has remaining time, put it back in the ready queue. Rem time decrements by quantum.
		else
		{
			next_clock = clock + quantum;
			//check for submissions
	/*			while (sub[i] <= clock && i < count)
			{
				ready[end] = i;
				rem_time[i] = run[i];
				printf("Process %d added. index=%d, end=%d, time-%d\n", i, index, end, rem_time[i]);
				end = (end + 1) % count;
				++i;
			}
			*/
			ready[end] = ready[index];
			rem_time[ready[index]] = rem_time[ready[index]] - quantum;
			printf("Process %d added to end of queue, position %d. %d remaining.\n", ready[index], end, rem_time[ready[end]]);
			end = (end + 1) % count;
//			printf("end %d ready[end] %d rem_time[end] %d\n", end, ready[end], rem_time[end] );
		}

		printf("job #%d, clock=%d, rem_time=%d, wait=%d, ta=%d, resp=%d\n\n", ready[index], clock, rem_time[ready[index]], wait, turnaround, response);
		index = (index + 1) % count;
		clock = next_clock;

	}
	printf("Round Robin with Time Quantum of %d\n", quantum);
	printf ("Avg. Resp.:%.2f, Avg. T.A:%.2f, Avg. Wait:%.2f\n",(float) response / count, (float) turnaround / count, (float) wait / count);
}
