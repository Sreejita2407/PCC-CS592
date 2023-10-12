#include<stdio.h>
#include<stdlib.h>



typedef struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
}CQue;

void initialization(CQue *q){
q->size=5;
q->rear=0;
q->front=0;
q->arr=(int*)malloc(5*sizeof(int));
}

void enque(CQue *q,int val){
  if((q->rear+1)%q->size==q->front){ return; }
  q->arr[q->rear]=val;
  q->rear=(q->rear+1)%q->size;
}

int deque(CQue *q){
  if(q->rear==q->front){ return -1; }
  int a=q->arr[q->front];
  q->front=(q->front+1)%q->size;
  return a;
}

