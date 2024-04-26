#include "tlpi_hdr.h"

// The C run-time startup code defines this variable and assigns the 
// location oif the environment list to it
extern char **environ;

int main(int argc, char *argv[]) {
	char **ep;

	for (ep = environ; *ep != NULL; ep++) {
		puts(*ep);
	}

	exit(EXIT_SUCCESS);
}
