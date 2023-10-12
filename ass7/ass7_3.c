#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>




void signal_handler(int signum) {
    if (signum == SIGUSR1) {


        int year;
        printf("Child: Enter a year to check if it's a leap year: ");
        scanf("%d", &year);




        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            printf("Child: %d is a leap year.\n", year);
        } else {
            printf("Child: %d is not a leap year.\n", year);
        }
    }
}


int main() {
    pid_t child_pid;




    if ((child_pid = fork()) == -1) {
        perror("fork");
        exit(1);
    }


    if (child_pid == 0) {


        signal(SIGUSR1, signal_handler);


        while (1) {
            sleep(1); 
        }
    } else {


        printf("Parent: Child process created with PID %d.\n", child_pid);
        
        while (1) {
     
            sleep(5);
            printf("Parent: Sending SIGUSR1 signal to the child.\n");
            kill(child_pid, SIGUSR1);
        }


        int status;
        waitpid(child_pid, &status, 0);
    }


    return 0;
}