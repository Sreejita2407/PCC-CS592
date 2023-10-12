#include <stdio.h>
#include <pthread.h>

void *summation(void *args){
	int n;
	printf("Enter number : ");
	scanf("%d", &n);
	int sum = (n*(n+1))/2;
	printf("Sum : %d\n", sum);
	pthread_exit(0);
}

int main(){
	pthread_t thread;
	pthread_create(&thread, NULL, &summation, NULL);
	pthread_join(thread, NULL);
	return 0;
}
