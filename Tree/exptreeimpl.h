#include"exptreeintfc.h"
#include<conio.h> 
void push(stack *s,struct node *c)
{
	if(isfull(s))
	{
		printf("stack is full");
		return;	
	}
	s->top++;
	(s->a[s->top])=c;	
}

struct node* nodeinit(char c)
{
	struct node *z;
	z=(struct node*)malloc(sizeof(struct node));
	z->p=c;
	z->r=NULL;
	z->l=NULL;
	return z;
}

stack* initialize()
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

void convert(ExpTree *t)
{
	char *c,*b;
	c=t->infix;
	b=t->postfix;
	struct node *n;
	t->s=initialize();
	int i=0,j=0,k;
	for(i=0;i<strlen(c);i++)
	{
		if(isopr(*(c+i)))
		{
			k=precedence(*(c+i));
			if(isempty(t->s))
			{
				push(t->s,nodeinit(*(c+i)));
			}
			else if(precedence(t->s->a[t->s->top]->p)<k)
			{
				push(t->s,nodeinit(*(c+i)));
			}
			else
			{
				while(t->s->top!=-1)
				{
					*(b+j)=t->s->a[t->s->top]->p;
					j++;
					n=popv(t->s);
				}
				push(t->s,nodeinit(*(c+i)));
			}
		}
		else if(isdigi(*(c+i)))
		{
			*(b+j)=c[i];
			j++;
		}	
	}
	if(!isempty(t->s))
	{
		while(t->s->top!=-1)
		{
			*(b+j)=t->s->a[t->s->top]->p;
			j++;
			n=popv(t->s);
		}
	}
	*(b+j)='\0';		
}
int precedence(char s)
{
	if(s=='+'||s=='-')
		return 1;
	else if(s=='*'||s=='/'||s=='%')
		return 2;
	else if(s=='^')
		return 3;
	else
		return 0;
}
int isopr(char s)
{
	if(s=='+'||s=='-'||s=='*'||s=='%'||s=='/'||s=='^')
	return 1;
	else
	return 0;
}
int isdigi(char s)
{
	if(s>='0'&&s<='9')
		return 1;
	else 
		return 0;
}
struct node* popv(stack *s)
{
	s->top--;
	return (s->a[s->top+1]);	
}
ExpTree* treeinit()
{
	ExpTree *t;
	t=(ExpTree*)malloc(sizeof(ExpTree));
	t->value=0;
	t->s=initialize();
	return t;
}
void InfixToPostfix(ExpTree *t)
{
	convert(t);
}

void Display(ExpTree *t)
{
	printf("Infix : %s\n",t->infix);
	printf("Postfix : %s\n",t->postfix);
	printf("Value : %d\n",t->value);
}

void evaluate(ExpTree *t)
{
	int i=0;
	struct node *n;
	char *c;
	c=t->postfix;
	int w=strlen(c);
	i=0;

	while(i<w)
	{	
		if(isdigi(c[i]))
		{
			push(t->s,nodeinit(c[i]));
		}
		else
		{
			n=nodeinit(c[i]);
			(*n).r=popv(t->s);
			(*n).l=popv(t->s);
			push(t->s,n);
			
		}
		i++;
	}
	n=popv(t->s);
	t->value=process(n);
}
int process(struct node *n)
{
	int operand1,operand2;char opr,a,b;
	if((n->l==NULL)&&(n->r==NULL))
	{	
		return (int)(n->p)-48;		
	}
	else
	{
		opr=n->p;
		operand1=process(n->l);
		operand2=process(n->r);
		return bc(opr,operand1,operand2);
	} 
}
int bc(char a,int x,int y)
{
	switch(a)
	{
		case '+':return x+y;
		case '-':return x-y;
		case '*':return x*y;
		case '/':return x/y;
		case '%':return x%y;
	}
return 0;
}