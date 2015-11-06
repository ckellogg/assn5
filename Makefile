assn5: assn5.c assn5.h fcfs.c sjf.c rr.c Makefile
	gcc -g -o assn5 assn5.c fcfs.c sjf.c rr.c srtf.c

clean: 
	rm assn5
