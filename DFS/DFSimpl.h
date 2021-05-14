#include"DFSintfc.h"


stack* initialize(int x)
{
	stack *s;
	s=(stack*)malloc(sizeof(stack));
	s->top=-1;
	
	s->size=x;
	return s;
}

int isfull(stack *s)
{
	if(s->top==s->size-1)
	return 1;
	return 0;
}
int isempty(stack *s)
{
	if(s->top==-1)
	return 1;
	return 0;
}
void push(stack *q,int x)
{
	if(isfull(q))
	{
		printf("stack is full\n");
		return;
	}
	q->a[++q->top]=x;
}
int pop(stack *q)
{
	if(isempty(q))
	{
		printf("stack is empty\n");
		return -1;
	}
	return q->a[--q->top];
}
int peek(stack *s)
{
	if(isempty(s))
	{
		printf("stack is empty\n");
		return -1;
	}
	return s->a[s->top];
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

void DFS(cityADT *c) 
{
  	stack *s;    int x, z, y;
  	int i;
  	s=initialize(c->n); 
	while(unvisited(c)!=-1) 
	{	
		x=unvisited(c);
		visit(c,x);
		push(s,x); 
		while (!isempty(s))
		{
			z = peek(s); 
			if(unvisitedNeighbour(c,z)!=-1)
			{	
				y=unvisitedNeighbour(c,z);
				visit(c,y);
				push(s,y); 
			}
			else
				i=pop(s);
			
		}
		printf("\n");
	}
	reset(c);
}

void checkConnectivity(cityADT *c,char s[100],char d[100]) 
{
  	stack *S;    int x, z, y;
	int i=0,j=0,k=0;;
	char vcs[100][100];
	S=initialize(c->n);
	x=checkpresence(c,s);
	if(x==-1)
	{
		printf("no match for source\n");
		return;
	}
	else
	{		
		printf("source found \n");
	}
	c->vs[x]=1;
	printf("%s\n",c->a[x]);	
	//strcpy(vcs[i++],c->a[x]);
	push(S,x);
	while (!isempty(S)&&j==0)
	{
		z = peek(S); 
		if(unvisitedNeighbour(c,z)!=-1&&j==0)
		{	
			y=unvisitedNeighbour(c,z);
			c->vs[y]=1;
			printf("%s\n",c->a[y]);			
			//strcpy(vcs[i++],c->a[y]);
			if(!strcmp(c->a[y],d))
			{
				j=1;
			}
			push(S,y); 
		}
		else
		{
			i=pop(S);
		}
	}
	if(j==0)
	{
		printf("Connection not present\n");
	}/*
	else
	{
		printf("Connection exists\n");
		for(j=0;j<i;j++);
		printf("%s\n",vcs[j]);
		printf("\n");
	}*/
	reset(c);
}
