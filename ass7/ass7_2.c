#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void alarm_handler(int signum) {
    printf("Parent: Received an alarm signal from the child. Resuming...\n");
}


int main() {
    pid_t child_pid;




    signal(SIGALRM, alarm_handler);




    if ((child_pid = fork()) == -1) {
        perror("fork");
        exit(1);
    }


    if (child_pid == 0) {
    
        sleep(2);  
        printf("Child: Sending alarm signal to the parent...\n");
        kill(getppid(), SIGALRM);  
        exit(0);
    } else {
      
        printf("Parent: Waiting for an alarm signal from the child...\n");
        pause(); 
        printf("Parent: Resumed after receiving an alarm signal.\n");


        int status;
        waitpid(child_pid, &status, 0);
        printf("Parent: Child process has exited.\n");
    }


    return 0;
}