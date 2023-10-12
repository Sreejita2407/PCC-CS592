#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <string.h>

int main(int argc,char* argv[]){
	char str[200],revstr[200];
	int shmid=shmget(1234,sizeof(str),0666);
	void* mystr=(void*)shmat(shmid,NULL,0);
	int res=1;
	strcpy(str,(char*)mystr);
	printf("Received from Process 1: %s\n",(char*)mystr);
	int i=0;
	int h=strlen(str)-1;
	while(h>=0){
		revstr[i++]=str[h--];	
	}
	revstr[i]='\0';
	res=(!strcmp(str,revstr))?1:0;
	*((int *)mystr)=res;
	 
	shmdt(mystr);
	return 0;
}
