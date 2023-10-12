#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <ctype.h>
#include <errno.h>
sem_t s;
pthread_t t1,t2;
void* pbody(void* args){
	int i=0;

		sem_wait(&s);
		printf("ba");
		sem_post(&s);
		i++;

}
void* ppbody(void* args){
	int i=0;

		sem_wait(&s);
		printf("ab");
		sem_post(&s);
		i++;

}
int main(){
	
	sem_init(&s,0,1);
	int i=1;
	while(i<=3){
		pthread_create(&t1,NULL,&pbody,NULL);
		pthread_create(&t2,NULL,&ppbody,NULL);
		pthread_join(t1,NULL);
		pthread_join(t2,NULL);
		i++;
	}
	printf("\n");
	return 0;
}
