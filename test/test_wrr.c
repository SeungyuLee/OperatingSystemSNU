#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <linux/sched.h>

#define SYSCALL_SCHED_SETWEIGHT 380
#define SYSCALL_SCHED_GETWEIGHT 381


int main(int argc, char* argv[]) {
	int weight=0;
	int fork=0;	

	pid_t pid;

	if( argc == 1 ) 
		return 0;

	weight = atoi(argv[1]);
	if( argc > 2)
		fork = atoi(argv[2]);	

	while(fork>0){

		pid = fork();
		
		printf(" **** tester for WRR works **** \n\n");
		printf(" --> set weight %d\n",weight); 
	
		syscall(SYSCALL_SCHED_SETWEIGHT, pid, weight);
		// need exit() ? 
	}
	
	return 0;
}