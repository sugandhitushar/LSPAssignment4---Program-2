#include"program.h"

#define MIN 1
#define MAX 500

void *ThreadProc(void *arg)
{
	int i, flag =  (int) arg;
	
	if(1 == flag)
	{
		for(i=MIN;i<=MAX;i++)
		{
			printf("Thread1: %d\n",i);
		}
	}
	else if(2 == flag)
	{
		for(i=MAX;i>=MIN;i--)
		{
			printf("Thread2: %d\n",i);
		}	
	}
	
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	pthread_t thread1,thread2;
	int ret;
	
	ret = pthread_create(&thread1, NULL, ThreadProc,(void *) 1);
	if(ret!=0)
	{
		printf("Thread not created. Error number: %d",ret);
		exit(EXIT_FAILURE);
	}
	
	ret = pthread_create(&thread2,NULL,ThreadProc,(void *) 2);
	if(ret!=0)
	{
		perror("pthread_create: thread2");
		exit(EXIT_FAILURE);
	}
	
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	printf("Threads terminated.\n");
	
	pthread_exit(NULL);
	return 0;
}

