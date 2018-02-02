#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

static int count=0;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;

void *thread_run(void *arg)
{
	int val=0;
	int i=0;
	for(;i<5000;++i)
	{
		pthread_mutex_lock(&mutex);
		val=count;
		printf("pthread id is %d,tid is%d\n",getpid(),pthread_self());
		count=val+1;
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

int main()
{
	pthread_t id1;
	pthread_t id2;
	int temp1=pthread_create(&id1,NULL,thread_run,NULL);
	int temp2=pthread_create(&id2,NULL,thread_run,NULL);
	if(temp1!=0)
	{
		printf("create thread1 error,%s\n",strerror(temp1));
		return -1;
	}
	if(temp2!=0)
	{
		printf("create thread1 error,%s\n",strerror(temp1));
		return -2;	
	}
	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	printf("count val = %d",count);
	return 0;
}
