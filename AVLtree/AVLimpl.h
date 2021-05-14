#include"AVLintfc.h"
struct tree* makeempty(struct tree *t)
{
	if(t!=NULL)
	{
		t->l=makeempty(t->l);
		t->r=makeempty(t->r);
		free(t);
	}
	return NULL;
}
int max(int a,int b)
{
	if(a>b)
	return a;
	return b;	
}
struct tree* find(struct tree *t, int x)
{
	if(t==NULL)
	{
		return NULL;
	}
	if(x<t->ele)
	{
		return find(t->l,x);
	}
	if(x>t->ele)
	{
		return find(t->r,x);
	}
	else
		return t;
}
struct tree* min(struct tree *t)
{
	if(t==NULL)
		return NULL;
	else if(t->l==NULL)
	{
		return t;
	}
	else
		return min(t->l);
}
int height(struct tree *t)
{
	if(t==NULL)
	{
		return -1;
	}
	else
		return t->height;
}
struct tree* tmax(struct tree *t)
{
	if(t==NULL)
	{
		return NULL;
	}
	else if(t->r==NULL)
	{
		return t;
	}
	else
	{
		return tmax(t->r);
	}
}
struct tree* SRL(struct tree *k2)
{
	struct tree *k1;
	k1=k2->l;
	k2->l=k1->r;
	k1->r=k2;

	k2->height=max(height(k2->l),height(k2->r))+1;
	k1->height=max(height(k1->l),k2->height)+1;
	return k1;
}
struct tree* SRR(struct tree *k2)
{
	struct tree *k1;
	k1=k2->r;
	k2->r=k1->l;
	k1->l=k2;

	k2->height=max(height(k2->l),height(k2->r))+1;
	k1->height=max(height(k1->r),k2->height)+1;
	return k1;
}
struct tree* DRL(struct tree *k3)
{
	k3->l=SRR(k3->l);
	return SRL(k3);
}
struct tree* DRR(struct tree *k3)
{
	k3->r=SRL(k3->r);
	return SRR(k3);
}
struct tree* insert(struct tree *t,int x)
{
	int hdiff;
	if(t==NULL)
	{
		t=(struct tree *)malloc(sizeof(struct tree));
		t->ele=x;
		t->l=t->r=NULL;
		t->height=0;
	}
	else if(x<t->ele)
	{
		t->l=insert(t->l,x);
		hdiff=abs(height(t->l)-height(t->r));
		if(hdiff==2)
		{
			//printf("Rotating\n");
			if(x<t->l->ele)
			t=SRL(t);
			else
			t=DRL(t);
		}
		t->height=max(height(t->l),height(t->r))+1;
		//printf("%d\n",hdiff);
	}
	else if(x>t->ele)
	{
		t->r=insert(t->r,x);

		hdiff=abs(height(t->l)-height(t->r));
		if(hdiff==2)
		{
			//printf("Rotating\n");
			if(x>t->r->ele)
			t=SRR(t);
			else
			t=DRR(t);
		}
		t->height=max(height(t->l),height(t->r))+1;
	}
	return t;
}
struct tree* del(struct tree *t,int x)
{
	struct tree *tmp;
	if(t==NULL)
		return NULL;
	else if(x<t->ele)
		t->l=del(t->l,x);
	else if(x>t->ele)
		t->r=del(t->r,x);
	else
	{
		if(t->l&&t->r)
		{
			tmp=min(t->r);
			t->ele=tmp->ele;
			t->r=del(t->r,tmp->ele);
		}
		else
		{
			tmp=t;
			if(t->r==NULL)
			t=t->l;
			else
			t=t->r;
			free(tmp);
		}
	}
	return t;
}
void display(struct tree *p,int tab)
{
	int i;
	printf("\n");
	for(i=1;i<=tab;i++)
		printf("    ");
	printf("%d",p->ele);
	if(p->l!=NULL)
		display(p->l,tab+1);
	
	
	if(p->r!=NULL)
		display(p->r,tab+1);
		
}