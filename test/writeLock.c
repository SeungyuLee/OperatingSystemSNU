#include <sys/syscalls.h>
#include <stdio.h>
#include <unistd.h>
#define SYSCALL_ROTLOCK_WRITE 382

int main(int argc, char* argv[])
{
	int arg1 = atoi(argv[1]);
	int arg2 = atoi(argv[2]);
	syscall(SYSCALL_ROTLOCK_WRITE, arg1, arg2);
	printf("rotlock_write from %d to %d\n", arg1-arg2, arg1+arg2);
	return 0;
}