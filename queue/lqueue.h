#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
	int a[100];
	int size,f,r;
}queue;
queue* initialize(int s);
int isfull(queue *q);
int isempty(queue *q);
void enqueue(queue *q,int x);
int dequeue(queue *q);

queue* initialize(int s)
{
	queue *q;
	q=(queue*)malloc(sizeof(q));
	q->f=0;
	q->r=0;
	q->size=s;
	return q;
}

int isfull(queue *q)
{
	if(q->r==q->size)
	return 1;
	return 0;
}
int isempty(queue *q)
{
	if(q->r<=q->f)
	return 1;
	return 0;
}
void enqueue(queue *q,int x)
{
	if(isfull(q))
	{
		printf("queue is full\n");
		return;
	}
	q->a[q->r]=x;
	q->r++;
}
int dequeue(queue *q)
{
	if(isempty(q))
	{
		printf("queue is empty\n");
		return -1;
	}
	q->f++;
	return q->a[q->f-1];
}
void display(queue *q)
{
	int i;
	for(i=q->f;i<q->r;i++)
	{
		printf("%d\n",q->a[i]);
	}
}

		

