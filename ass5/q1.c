#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t child_pid;

    // Create a child process
    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        // This code runs in the child process
        printf("Child Process - PID: %d, PPID: %d\n", getpid(), getppid());
    } else {
        // This code runs in the parent process
        printf("Parent Process - PID: %d, PPID: %d\n", getpid(), getppid());
    }

    return 0;
}