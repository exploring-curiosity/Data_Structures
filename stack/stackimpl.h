#include"interface.h"
void push(stack *s,char c)
{
	if(isfull(s))
	{
		printf("stack is full");
		return;	
	}
	s->top++;
	s->a[s->top]=c;	

}
void pop(stack *s)
{
	if(isempty(s))
	{
		printf("stack is empty");
		return;	
	}
	
	printf("deleted: %c\n",s->a[s->top]);
	s->top--;	
}
stack * initialize()
{
	stack *s;
	s=(stack *)malloc(sizeof(stack));
	s->top=-1;
	s->size=100;
	return s;
}
int isfull(stack *s)
{
	if(s->top==s->size-1)
	{
		return 1;
	}
	return 0;
}
int isempty(stack *s)
{
	if(s->top==-1)
	{
		return 1;
	}
	return 0;
}
void display(stack *s)
{
	int i=0;
	if(isempty(s))
	{
		printf("empty\n");
		return;
	}
	for(i=0;i<=s->top;i++)
	{
		printf("%c\n",s->a[i]);
	}	
}

