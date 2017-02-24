#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<pthread.h>
#include<signal.h>
#define N  5
#define LEFT  (i+N-1)%N
#define RIGHT (i+1)%N
#define THINKING 0
#define HUNGRY 1
#define EARTING 2
int state[N];
//typedef int samaphore;
int all=0;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t s[N];
pthread_t thread[N];

void philosopher(void* something);//if u dont put this before it will have warning 
void take_forks(int i);//if u dont put this before it will have warning 
void put_forks(int i);//if u dont put this before it will have warning 
void test(int i);//if u dont put this before it will have warning 
void bye(int t);
int main()
{
	printf("B023040020 hw2 eat spagetti\n");
	int j;
	for(j=0;j<N;j++)
	{
		pthread_create(&thread[j], NULL ,philosopher,(void*)j);				
	}
	signal(SIGINT, bye);
	while(1)
	{	
		pthread_mutex_lock(&mutex);
		for(j=0;j<N;j++)
		{
			if(state[j]==THINKING)
				printf("think  ");
			else if(state[j]==HUNGRY)
				printf("hungry ");
			else if(state[j]==EARTING)
				printf("eating ");
		}
		printf("\n\n@@@@@@@@@@@@@@@@@\n\n");
		//printf("ASadffffffffffffffffffffffffffffffffffffffffffff\n");
		pthread_mutex_unlock(&mutex);sleep(1);
	}
	
	return 0;
}
void bye(int t)
{	
	//t=100;
	all=1;
	while(1)
	{	
		pthread_mutex_lock(&mutex);
		int j;
		for(j=0;j<N;j++)
		{
			if(state[j]==THINKING)
				printf("think  ");
			else if(state[j]==HUNGRY)
				printf("hungry ");
			else if(state[j]==EARTING)
				printf("eating ");
		}
		printf("\n\n@@@@@@@@@@@@@@@@@\n\n");
		if(state[0]==THINKING&&state[1]==THINKING&&state[2]==THINKING&&state[3]==THINKING&&state[4]==THINKING)
		{				
		
				break;
		}
	
		pthread_mutex_unlock(&mutex);sleep(1);
	}	
	//pthread_mutex_unlock(&mutex);
	printf("bye bye and thank u \n");
	
	exit(0);
}
void philosopher(void* something)
{	
	int i =(int*)something;
	while(1)
	{
		//think();
		signal(SIGINT, bye);
		take_forks(i);
		//eat();
		put_forks(i);
		if(all==1)
			break;
	}
	printf("%d goodbye\n",i);
	sleep(1);	
}
void take_forks(int i)
{
	pthread_mutex_lock(&mutex);
	state[i]=HUNGRY;
	test(i);
	pthread_mutex_unlock(&mutex);
	pthread_mutex_lock(&s[i]);
}
void put_forks(int i)
{
	pthread_mutex_lock(&mutex);
	state[i]=THINKING;
	test(LEFT);
	test(RIGHT);	
	pthread_mutex_unlock(&mutex);
}
void test(int i)
{
	if(state[i]==HUNGRY&&state[LEFT]!=EARTING&&state[RIGHT]!=EARTING)
	{
		state[i]=EARTING;
		pthread_mutex_unlock(&s[i]);	
	}
}
