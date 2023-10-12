#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

int main(int argc,char* argv[]){
	char str[200];
	int shmid=shmget(1234,sizeof(str),0666|IPC_CREAT);
	int res=-1;
	void* mystr=(void*)shmat(shmid,NULL,0);
	printf("Enter an input string to check for palindrome:");
	scanf("%s",str);
	strcpy((char*)mystr,str);
	sleep(10);
	res=*((int*)mystr);
	if(res==1){
		printf("Palindrome\n");
	}
	else{
		printf("Not Palindrome\n");
	}
	shmdt(mystr);
	shmctl(shmid,IPC_RMID,NULL);
	return 0;
}
