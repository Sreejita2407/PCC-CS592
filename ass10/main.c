#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
#include<time.h>
#include<sys/wait.h>
#include "cirqueue.c"

#define TH_NUM 2

sem_t semEmpty,semFull;
CQue que;


void* producer(){
 while(1){
   int x=rand()%100;
   sem_wait(&semEmpty);
   enque(&que,x);
   sem_post(&semFull);
   printf("Produced data: %d\n",x);
 }
}

void* consumer(){
   while(1){
   int y;
   sem_wait(&semFull);
   y=deque(&que);
   sem_post(&semEmpty);
   if(y==-1){ printf("No data recived by consumer\n"); }
   else{ printf("Recived data: %d\n",y); }
   sleep(1);
   }
}

int main(){
  initialization(&que);
  srand(time(NULL));
  pthread_t th[TH_NUM];
  sem_init(&semEmpty,0,5);
  sem_init(&semFull,0,0);
  
  int i;
  for(i=0;i<TH_NUM;i++){
   if(i>0){
   if(pthread_create(&th[i],NULL,&producer,NULL)!=0){ printf("Fail to create thread\n");  }
   }else{
   if(pthread_create(&th[i],NULL,&consumer,NULL)!=0){ printf("Fail to create thread\n"); }
   } 
  }
  
  for(i=0;i<TH_NUM;i++){
    pthread_join(th[i],NULL);
  }
  
  sem_destroy(&semEmpty);
  sem_destroy(&semFull);
  
return 0;
}
