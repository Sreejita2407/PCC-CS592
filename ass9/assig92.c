#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void* body(void* args){
	int n=*((int*)args);
	int flag=0;
	int i=2;
	if(n==1){
		printf("NOT PRIME");
		return NULL;
	}
	for(;i*i<=n;i++){
		if(n%i==0){
			flag=1;
			break;
		}
	}
	if(flag==0){
		printf("PRIME\n");
	}else{
		printf("NOT PRIME\n");
	}
	return NULL;
}
int main(){

	pthread_t st;
	int n;
	while(1){
		printf("Enter 0 to exit else enter any number > 0 ");
		fscanf(stdin,"%d",&n);
		if(n==0)
		break;
		pthread_create(&st,NULL,&body,&n);
		pthread_join(st,NULL);
	}
	return 0;
}
