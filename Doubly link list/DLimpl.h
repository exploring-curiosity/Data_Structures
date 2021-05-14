#include"DLproto.h"
struct dbl * initialize()
{
	struct dbl *x;
	x=(struct dbl*)malloc(sizeof(struct dbl));
	x->prev=NULL;
	x->next=NULL;
	return x;
}
void insertfront(struct dbl *h,struct dbl *t,personal a)
{
	struct dbl *temp;
	temp=(struct dbl*)malloc(sizeof(struct dbl));
	temp->p=a;
	temp->prev=h;
	temp->next=h->next;
	h->next->prev=temp;
	h->next=temp;
}
void insertend(struct dbl *h,struct dbl *t,personal a)
{
	struct dbl *temp;
	temp=(struct dbl*)malloc(sizeof(struct dbl));
	temp->p=a;
	temp->prev=t->prev;
	temp->next=t;
	t->prev->next=temp;
	t->prev=temp;
}
void insertpin(struct dbl *h,struct dbl *t,personal a,int pin)
{
	struct dbl *temp,*x;
	x=h;
	temp=(struct dbl*)malloc(sizeof(struct dbl));
	while(x->next!=NULL)
	{
		x=x->next;
		if(x->p.no==pin)
		break;
	}
	temp->p=a;
	temp->prev=x;
	temp->next=x->next;
	x->next->prev=temp;
	x->next=temp;
}
struct dbl * seniorperson(struct dbl *h)
{
	struct dbl *temp,*head,*tail;
	head=initialize();
	tail=initialize();
	head->next=tail;
	tail->prev=head;
	temp=h;
	while(temp->next!=NULL)
	{
		temp=temp->next;
		if(temp->p.age>=50)
		{
			insertfront(head,tail,temp->p);
		}
	}
	return head;
}
struct dbl * locateperson(struct dbl *h,char loc[100])
{
	struct dbl *temp,*head,*tail;
	head=initialize();
	tail=initialize();
	head->next=tail;
	tail->prev=head;
	temp=h;
	while(temp->next!=NULL)
	{
		temp=temp->next;
		if(!strcmp(temp->p.address,loc))
		{
			insertfront(head,tail,temp->p);
		}
	}
	return head;
}
void display(struct dbl *h)
{
	struct dbl *l;
	l=h->next;
	while(l->next!=NULL)
	{
		disp(l->p);
		l=l->next;
	}
}
void sort(struct dbl *h,struct dbl *t)
{
	struct dbl *temp,*temp1;
	int i,j;
	temp=h->next;
	temp1=h->next;
	personal w;
	while(temp->next->next!=NULL)
	{
		temp1=h->next;
		while(temp1->next->next!=NULL)
		{
			if(temp1->p.age>temp1->next->p.age)
			{
				w=temp1->p;
				temp1->p=temp1->next->p;
				temp1->next->p=w;
			}
			temp1=temp1->next;
		}
		temp=temp->next;
	}	
}
void getinfo(personal *p)
{
	printf("Enter the name: ");
	scanf("%s",p->name);
	printf("Enter the Address: ");
	scanf("%s",p->address);
	printf("Enter the Gender: ");
	scanf("%s",&(p->gender));
	printf("Enter the age : ");
	scanf("%d",&(p->age));
	p->no=(rand()%99+1)*(rand()%9+1)+1000;
	printf("Generated pin : %d",p->no);
}
void disp(personal p)
{
	printf("Name: ");
	printf("%s\n",p.name);
	printf("Age : ");
	printf("%d\n",p.age);

	printf("Address: ");
	printf("%s\n",p.address);
	printf("Gender: ");
	printf("%c\n",p.gender);
	printf("Generated pin : %d\n",p.no);
}

/*void rdisplay(struct dbl *t)
{
	struct dbl *l;
	l=t->prev;
	while(l->prev!=NULL)
	{
		disp(l->p);
		l=l->prev;
	}
}*/

ratio adultperson(struct dbl *l)
{
	ratio r;
	r.m=0;
	r.f=0;
	struct dbl *x;
	x=l;
	while(x->next!=NULL)
	{
		x=x->next;
		if(x->p.gender=='m')
		r.m++;
		else
		r.f++;
	}
	return r;
}