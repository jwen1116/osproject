#include <stdio.h>
#include <pthread.h>
#include <string.h>

struct data{
	int id;
	char name[64];
};

void* tafx(void *arg){
	struct data *mydata=arg;
	int myid=mydata->id;
	char myname[64];
	strcpy(myname,mydata->name);
	printf("I am child, my id: %d, my name: %s\n",myid,myname);
	return NULL;
}

void* tbfx(void *arg){
	struct data *mydata=arg;
	int myid=mydata->id;
	printf("I am child, my id: %d\n",myid);
	return NULL;
}

int main(){
	pthread_t ta,tb;
	struct data tadata,tbdata;
	tadata.id=12;
	tbdata.id=79;
	strcpy(tadata.name,"Adam");
	strcpy(tbdata.name,"Eve");

	if (pthread_create(&ta,NULL,&tafx,&tadata)!=0){
		printf("error creating thread ta");
	}
	
	if (pthread_create(&tb,NULL,&tafx,&tbdata)!=0){
		printf("error creating thread tb");
	}

	pthread_join(ta,NULL);
	pthread_join(tb,NULL);
	
	return 0;
}
