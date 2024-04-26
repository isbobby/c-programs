#include <stdlib.h>
#include <stdio.h>

int main() {
	char* myEnv;
	char* myVal;
	myEnv = "cpenv";
	myVal = "cpval";

	int overwrite = 0;

	setenv(myEnv, myVal, overwrite); 

	char* gotVal;
	gotVal = getenv(myEnv);

	printf("set & get env, %s=%s\n", myEnv, gotVal);

	exit(EXIT_SUCCESS);
}
