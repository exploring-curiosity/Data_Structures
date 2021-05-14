#include"stackimpl.h"
void main()
{
	char s[100],s1[100];
	int k;	
	printf("enter the expression\n");
	scanf(" %s",s);
	convert(s,s1);
	k=evaluate(s1);

	printf("posfix : %s\n",s1);
	printf("the result is : %d\n",k);
}
void convert(char c[100],char b[100])
{
	stack *s;
	s=initialize();
	int i=0,j=0,k;
	for(i=0;i<strlen(c);i++)
	{
		if(isopr(c[i]))
		{
			k=precedence(c[i]);
			if(isempty(s))
			{
				push(s,c[i]);
			}
			else if(precedence(s->a[s->top])<k)
			{
				push(s,c[i]);
			}
			else
			{
				while(s->top!=-1)
				{
					b[j]=s->a[s->top];
					j++;
					popv(s);
				}
				push(s,c[i]);
			}
		}
		else if(isdigi(c[i]))
		{
			b[j]=c[i];
			j++;
		}	
	}
	if(!isempty(s))
	{
		while(s->top!=-1)
		{
			b[j]=s->a[s->top];
			j++;
			popv(s);
		}
		
	}		
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
void popv(stack *s)
{
	if(isempty(s))
	{
		printf("stack is empty");
		return;	
	}
	
	s->top--;	
}
int evaluate(char b[100])
{
	int i=0,x,y;
	stack *s;
	s=initialize();
	for(i=0;i<strlen(b);i++)
	{
		if(isdigi(b[i]))
		{
			push(s,(int)b[i]-48);
		}		
		else if(isopr(b[i]))
		{
			x=s->a[s->top-1];
			y=s->a[s->top];
			popv(s);
			popv(s);
			push(s,bc(b[i],x,y));
		}
	}
	return s->a[s->top];			
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
		//case '^':return pow(x,y);
	}
return 0;
}
/*
PS F:\data structures\stack> gcc stackapplv3.c -o k
PS F:\data structures\stack> ./k
enter the expression
5+4*3-2+6/3+7
posfix : 543*+2-63/+7+
the result is : 24
*/