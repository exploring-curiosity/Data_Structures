#include"prototype.h"
struct poly * initialize(struct poly *p)
{
	p=(struct poly*)malloc(sizeof(struct poly));
	p->next=NULL;
	return p;
}
void insertFront(struct poly *p,term x)
{	
	struct poly *temp;
	temp = (struct poly*)malloc(sizeof(struct poly));
	temp->t=x;
	
	temp->next=p->next;
	p->next=temp;
}
void insertEnd(struct poly *p,term x)
{
	struct poly *temp=p;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}	
	struct poly *tr;
	tr=(struct poly*)malloc(sizeof(struct poly));
	tr->t=x;
	tr->next=temp->next;
	temp->next=tr;
}
void display(struct poly *p)
{
	struct poly *temp;
	temp=p;
	while(temp->next!=NULL)
	{
		temp=temp->next;
		if(temp->next!=NULL)
		{
			
			printf("%d^%d + ",temp->t.coeff,temp ->t.expo);
		}
		else
		{
			
			printf("%d^%d ",temp->t.coeff,temp ->t.expo);
		}
	}
	printf("\n");
}
term getterm()
{
	term t;
	printf("enter the exponent value : ");
	scanf("%d",&t.expo);
	printf("enter the coefficient : ");
	scanf("%d",&t.coeff);
	return t;
}
void insertAfterTerm(struct poly *p,term x,int exp)
{
	struct poly *temp;
	temp=p;
	while(temp->t.expo!=exp)
	{
		temp=temp->next;
	}
	struct poly *tr;
	tr=(struct poly*)malloc(sizeof(struct poly));
	tr->t=x;
	tr->next=temp->next;
	temp->next=tr;
}
struct poly * polyadd(struct poly *p1,struct poly *p2)
{
	int m,n;
	struct poly *p3;
	struct poly *t1;
	struct poly *t2;
	t1=p1;
	t2=p2;
	term r;
	m=polyDegree(p1);
	n=polyDegree(p2);
	p3=initialize(p3);
	int max;
	max=(m>=n?m:n);
	int i,j;
	for(i=max;i>=0;i--)
	{
		r.expo=i;
		r.coeff=0;
		while(t1->next!=NULL)
		{
			t1=t1->next;
			if((t1->t.expo==i))
			r.coeff+=t1->t.coeff;
		}t1=p1;
		while(t2->next!=NULL)
		{
			t2=t2->next;
			if((t2->t.expo==i))
			r.coeff+=t2->t.coeff;
			
		}t2=p2;
		insertEnd(p3,r); 
	}
	return p3;
}
struct poly * polymul(struct poly *p1,struct poly *p2)
{
	int m,n,i,j;
	struct poly *p3;
	struct poly *t1;
	struct poly *t2;
	t1=p1;
	t2=p2;
	p3=initialize(p3);
	term r;
	m=polyDegree(p1);
	n=polyDegree(p2);
	while(t1->next!=NULL)
	{
		t1=t1->next;
		while(t2->next!=NULL)
		{
			t2=t2->next;
			r.expo=t1->t.expo+t2->t.expo;
			r.coeff=t1->t.coeff*t2->t.coeff;
			insertEnd(p3,r);
		}t2=p2;
	}
	p3=order(p3);
	return p3;
}
int polyDegree(struct poly *p)
{
	int max=0;
	struct poly *temp;
	temp=p;
	while(temp->next!=NULL)
	{
		temp=temp->next;
		if(temp->t.expo>max)
		max=temp->t.expo;
	}
	return max;
}
struct poly * order(struct poly *p)
{
	struct poly *p4,*temp;
	p4=initialize(p4);
	temp=p;
	term r;
	int max=polyDegree(p);
	int i;
	for(i=max;i>=0;i--)
	{
		r.coeff=0;
		r.expo=i;
		while(temp->next!=NULL)
		{
			temp=temp->next;
			if(temp->t.expo==i)
			r.coeff+=temp->t.coeff;
		}
		temp=p;
		if(r.coeff!=0)
		insertEnd(p4,r);
	}
	return p4;
}
int evaluate(struct poly *p,int x)
{
	struct poly *temp;
	temp=p;
	int sum=0,i,k,res=0;
	term a;
	while(temp->next!=NULL)
	{
		k=1;
		temp=temp->next;
		for(i=0;i<temp->t.expo;i++)
		{
			k*=x;
		}
		k*=temp->t.coeff;
		sum+=k;
	}
	return sum;

}
void getpoly(struct poly *p)
{
	term x;
	int rep;
	int ch;
	do
	{
		printf("Enter Coefficient:");
		scanf("%d",&x.coeff);
		printf("Enter its Exponent:");
		scanf("%d",&x.expo);
		printf("How do you want to insert it?\n");
		printf("1.Insert front\n 2. Insert End \n 3.Insert After a Exponent ");
		scanf("%d",&ch);
		int r;
		switch(ch)
		{
			case 1 :insertFront(p,x);break;
			case 2 :insertEnd(p,x);break;
			case 3 :printf("enter the exponent: ");
				    scanf("%d",&r);
				    insertAfterTerm(p,x,r);	
				    break;
			default:printf("invalid!!!");
		}
		printf("Insert another term (1/0) : ");
		scanf("%d",&rep);
	}while(rep==1);
}