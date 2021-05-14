#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
	int m[100][100];
	int n;
	int vs[100];
	char a[100][100];
}cityADT;
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
int queuetime(queue *q);
cityADT* create(cityADT *c);
void disp(cityADT *c);
int unvisited(cityADT *c);
int unvisitedNeighbour(cityADT *c,int x);
void visit(cityADT *c,int x);
void reset(cityADT *c);
void BFS(cityADT *c);
int checkConnectivity(cityADT *c,char s[100],char d[100]);
