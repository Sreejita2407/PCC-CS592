#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256

int main() {
    int pipe_fd[2];
    pid_t child_pid;
    char message[BUFFER_SIZE];
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    if ((child_pid = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {  /
        close(pipe_fd[1]);

               printf("Child: Enter a message: ");
        fgets(message, BUFFER_SIZE, stdin);

              write(pipe_fd[0], message, strlen(message));

               close(pipe_fd[0]);
    } else {  
        close(pipe_fd[0]);

               read(pipe_fd[1], message, BUFFER_SIZE);

               close(pipe_fd[1]);

        printf("Parent received message from child: %s", message);
    }

    return 0;
}
