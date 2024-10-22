#include <stdio.h>
#include <unistd.h>

#define ECHO_SIZE 20

int main() {
    char buffer[ECHO_SIZE];

    printf("Bad Echo Example, enter something:\n");

    read(STDIN_FILENO, buffer, ECHO_SIZE);

    printf("Bad Echo: %s", buffer);

    printf("\nProper Echo Example, enter something:\n");

    char goodBuffer[ECHO_SIZE];
    ssize_t numRead;
    numRead = read(STDIN_FILENO, goodBuffer, ECHO_SIZE);

    goodBuffer[numRead] = '\0';
    printf("Read: %zd, Proper Echo: %s", numRead, goodBuffer);
}