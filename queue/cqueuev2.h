#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int jobno,bursttime;
}job;
typedef struct 
{
	job a[100];
	int size,f,r;
}queue;

queue* initialize(int s);
int isfull(queue *q);
int isempty(queue *q);
void enqueue(queue *q,job x);
job dequeue(queue *q);
int queuetime(queue *q);

void disp(job j)
{
	printf("J%d:%d\n",j.jobno,j.bursttime);
}


queue* initialize(int s)
{
	queue *q;
	q=(queue*)malloc(sizeof(q));
	q->f=0;
	q->r=0;
	q->size=s+1;
	return q;
}

int isfull(queue *q)
{
	if(((q->r==q->size-1)&&(q->f==0))||(q->r+1==q->f))
	return 1;
	return 0;
}
int isempty(queue *q)
{
	if(q->r==q->f)
	return 1;
	return 0;
}
void enqueue(queue *q,job x)
{
	if(isfull(q))
	{
		printf("queue is full\n");
		return;
	}
	q->a[q->r]=x;
	q->r=(q->r+1)%q->size;
}
job dequeue(queue *q)
{
	job a;
	a.bursttime=-1;
	a.jobno=-1;
	if(isempty(q))
	{
		printf("queue is empty\n");
		return a;
	}
	int x=q->f;
	q->f=(x+1)%q->size;
	return q->a[x];
}
void display(queue *q)
{
	int i;
	if(q->f<q->r)
	{
		for(i=q->f;i<q->r;i++)
		{
			disp(q->a[i]);
		}
	}
	else if(q->f>q->r)	
	{
		for(i=q->f;i<q->size;i++)
		{
			disp(q->a[i]);
		}
		for(i=0;i<q->r;i++)
		{
			disp(q->a[i]);
		}
	}		
}

int queuetime(queue *q)
{
	int i,sum=0;
	if(q->f<q->r)
	{
		for(i=q->f;i<q->r;i++)
		{
			sum+=q->a[i].bursttime;	
		}
	}
	else if(q->f>q->r)	
	{
		for(i=q->f;i<q->size;i++)
		{
			sum+=q->a[i].bursttime;
		}
		for(i=0;i<q->r;i++)
		{
			sum+=q->a[i].bursttime;
		}
	}
	return sum;		
}
