#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <sys/errno.h>

#define MAX_READ 20

// copies standard input until eof;
// wrtites a copy of the input to the standard output;
// and to the file named in its command-line argument;
//
// with the -a flag, it appends to the file with give name;
//
// the following implements tee -a  
int main(int arg, char **argv) {
	if (arg != 3) {
		printf("Needs 2 arguments\n");
		return 1;
	}

	printf("input file:%s\n", argv[1]);
	printf("output file:%s\n", argv[2]);

	int fdIn, fdOut;
	int errno;
	fdIn = open(argv[1], O_RDWR);
	if (fdIn == -1) {
		printf("failed to open input file\n");
		return 1;
	}

	fdOut = open(argv[2], O_RDWR | O_CREAT, 0666);
	if (fdOut == -1) {
		if (errno == EACCES) {
			printf("failed to open output file, no sufficient access to the output file\n");
		}
		return 1;
	}

	printf("-- in_fd:%d, out_fd:%d\n", fdIn, fdOut);

	char buffer[MAX_READ + 1];
	ssize_t numRead;
	numRead = read(fdIn, buffer, MAX_READ);
	if (numRead == -1) {
		printf("-- [ERROR]: failed to read input file\n");
	}

	write(fdOut, buffer, numRead);

	return 0;
}
