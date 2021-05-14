#include"BFSintfc.h"


queue* initialize(int s)
{
	queue *q;
	q=(queue*)malloc(sizeof(queue));
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
void enqueue(queue *q,int x)
{
	if(isfull(q))
	{
		printf("queue is full\n");
		return;
	}
	q->a[q->r]=x;
	q->r=(q->r+1)%q->size;
}
int dequeue(queue *q)
{
	if(isempty(q))
	{
		printf("queue is empty\n");
		return -1;
	}
	int x=q->f;
	q->f=(x+1)%q->size;
	return q->a[x];
}
int checkpresence(cityADT *c,char s[])
{
	int i;
	for(i=0;i<c->n;i++)
	{
		if(!strcmp(s,c->a[i]))
		return i;
	}
	return -1;
}
cityADT* create(cityADT *c)
{
	int i,j;
	char s[100],rep;
	c=(cityADT*)malloc(sizeof(cityADT));
	printf("Enter no of citites : ");
	scanf("%d",&c->n);
	printf("enter the cities\n");
	int n=c->n;
	for(i=0;i<n;i++)
	{	
		scanf(" %s",c->a[i]);
		c->vs[i]=0;
	}
	for(i=0;i<n;i++)
	{for(j=0;j<n;j++)
	c->m[i][j]=0;}
	for(i=0;i<n;i++)
	{
		printf("Enter Neighbours of %s:\n",c->a[i]);
		printf("Are there any neighbours?y/n : ");
		scanf(" %c",&rep);	
		while(rep=='y')
		{
			scanf("%s",s);
			j=checkpresence(c,s);
			if(j==-1)
			{
				printf("city not recognized\n");
			}
			else
			{	
				printf("city found at : %d \n",j);
				c->m[i][j]=1;
			}
			printf("Are there any more neighbours?y/n : ");	
			scanf(" %c",&rep);
		}
	}	



	return c;
}
void disp(cityADT *c)
{
	int i,j,n=c->n;
	printf("   ");
	for(i=0;i<n;i++)
	{
		printf("\t%d",i);
	}
	printf("\n   ");
	for(i=0;i<n;i++)
	{
		printf("______");
	}
	printf("______\n\n");
	for(i=0;i<n;i++)
	{
		printf("%d |",i);
		for(j=0;j<n;j++)
		{	
			printf("\t");
			printf("%d",c->m[i][j]);
		}printf("   |");
		if(i+1<n)			
		printf("\n\n");
	}
	printf("\n   ");
	for(i=0;i<n;i++)
	{
		printf("______");
	}
	printf("______\n");
}

int unvisited(cityADT *c)
{
	int i;
	for(i=0;i<c->n;i++)
	{
		if(c->vs[i]==0)
		return i;
	}
	return -1;
}

int unvisitedNeighbour(cityADT *c,int x)
{
	int i;
	for(i=0;i<c->n;i++)
	{
		if(c->vs[i]==0&&c->m[x][i]==1)
		return i;
	}
	return -1;
}
void visit(cityADT *c,int x)
{
	c->vs[x]=1;
	printf("%s\t",c->a[x]);
}
void reset(cityADT *c)
{
	int j;
	for(j=0;j<c->n;j++)
	{
		c->vs[j]=0;
	}
}

void BFS(cityADT *c) 
{
  	queue *Q;    int x, z, y;
  	int i;
  	Q=initialize(c->n); 
	while(unvisited(c)!=-1) 
	{	
		x=unvisited(c);
		visit(c,x);
		enqueue(Q,x); 
		while (!isempty(Q))
		{
			z = dequeue(Q); 
			while(unvisitedNeighbour(c,z)!=-1)
			{	
				y=unvisitedNeighbour(c,z);
				visit(c,y);
				enqueue(Q,y); 
			}
			
		}
		printf("\n");
	}
	reset(c);
}
int checkConnectivity(cityADT *c,char s[100],char d[100]) 
{
  	queue *q;    int x, z, y;
  	q=initialize(c->n);
	for(x=0;x<c->n;x++)
	{
		if(!strcmp(s,c->a[x]))
		break;
	}
	if(x==c->n)
	{
		printf("no match for source\n");
		return 0;
	}
	else
	{
		printf("source found \n");
	}
	c->vs[x]=1;
	enqueue(q,x);
	while (!isempty(q))
	{
		z = dequeue(q); 
		while(unvisitedNeighbour(c,z)!=-1)
		{	
			y=unvisitedNeighbour(c,z);
			c->vs[y]=1;
			if(!strcmp(c->a[y],d))
			{
				return 1;
			}
			enqueue(q,y); 
		}
	}
	return 0;
}
