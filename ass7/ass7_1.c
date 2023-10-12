#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


void signal_handler(int signum) {
    printf("Received signal %d. Exiting gracefully.\n", signum);
    exit(0);
}


int main() {


    signal(SIGINT, signal_handler);


    printf("Press Ctrl+C to interrupt the program.\n");




    while (1) {
        printf(" \n the message shows continuously until the signal arrived \n ");
        sleep(1);
    }


    return 0;
}