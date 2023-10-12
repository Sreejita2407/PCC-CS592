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
        sleep(5); // Sleep to keep the child process alive
        printf("Child Process exiting.\n");
    } else {
        // This code runs in the parent process
        printf("Parent Process - PID: %d\n", getpid());

        // Sleep for a while to let the child process start
        sleep(2);

        printf("Parent Process exiting.\n");
        exit(EXIT_SUCCESS);
    }

    return 0;
}
