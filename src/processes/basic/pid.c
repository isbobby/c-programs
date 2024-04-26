#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main() {
	printf("process id:%ld\n", (long)getpid());

	printf("process parent id:%ld\n", (long)getppid());

	return 0;
}
