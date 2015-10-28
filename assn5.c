//Cody Kellogg
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

#include<unistd.h>		/*printf */
#include<stdio.h>		/*exit */
#include<stdlib.h>
#include<sys/wait.h>
#include<semaphore.h>
#include"assn5.h"
#define MAX_PROC (100)

			//shared data
int
main (int argc, char *argv[])
{
  int sub[MAX_PROC], run[MAX_PROC];
  int count = 0;

  if (argc == 1)
  {	
    printf("Submit time:Duration\n");
  }
  FILE *f = stdin;
  if (argc > 1)
    {
      f = fopen (argv[1], "r");	//creates a pointer to the file. the name comes from argv[1]
    }
  if (f == NULL)
    {
      perror ("Error Opening file");
	return -1;
    }
  while (fscanf (f, "%d %d", &sub[count], &run[count]) == 2) count++;


  fcfs (count, sub, run);
  sjf (count, sub, run);
//      srtf(count, sub ,run);
//      rr(count, sub ,run);
//



}
