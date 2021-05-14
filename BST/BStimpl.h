#include"BSTintfc.h"
struct playerProfile* initialize(struct playerProfile *p)
{
	p=(struct playerProfile*)malloc(sizeof(struct playerProfile));
	p->left=NULL;
	p->right=NULL;
}
struct playerProfile* insert(struct playerProfile *p,char n[100])
{
	if(p==NULL)
	{
		p=initialize(p);
		strcpy(p->name,n);
	}
	else if(strcmp(n,p->name)<0)
	{
		p->left=insert(p->left,n);
	}
	else if(strcmp(n,p->name)>0)
	{
		p->right=insert(p->right,n);
	}
	else
		printf("Insertion not possible player already exists\n");
	return p;
}
struct playerProfile* find(struct playerProfile *p,char n[100])
{
	if(p==NULL)
	{
		return NULL;
	}
	else if(strcmp(n,p->name)<0)
	{
		return find(p->left,n);
	}
	else if(strcmp(n,p->name)>0)
	{
		return find(p->right,n);
	}
	else if(strcmp(n,p->name)==0)
	{
		return p;
	}
}
struct playerProfile* findmin(struct playerProfile *p)
{
	if(p->left==NULL)
	{
		return p;
	}
	else
	{
		return findmin(p->right);
	}	
}


	
void display(struct playerProfile *p,int w)
{
	int i;
	printf("\n");
	for(i=1;i<=w;i++)
		printf("    ");
	printf("%s",p->name);
	
	if(p->left!=NULL)
	{
		printf("\n   left:");
		display(p->left,w+1);
	}
	if(p->right!=NULL)
	{
		printf("\n   right:");
		display(p->right,w+1);
	}		
}
struct playerProfile* Delete(struct playerProfile* p,char n[100])
{
	struct playerProfile *temp;	
	if(p==NULL)
	{
		return NULL;
	}
	if(strcmp(n,p->name)<0)
	{
		p->left=Delete(p->left,n);
	}
	if(strcmp(n,p->name)>0)
	{
		p->right=Delete(p->right,n);
	}
	else	
	{
		if(p->left&&p->right)
		{
			temp=findmin(p->right);
			strcpy(p->name,temp->name);
			p->right=Delete(p->right,n);
		}
		else
		{
			temp=p;
			if(p->right=NULL)
			{	
				p=p->left;
			}
			if(p->left==NULL)
			{
				p=p->right;
			}
			free(temp);
		}
	}	
	return p;
}
void inorder(struct playerProfile *t)
{
	inorder(t->left);
	printf("%s,",t->name);
	inorder(t->right);
}
void postorder(struct playerProfile *t)
{
	inorder(t->left);
	inorder(t->right);
	printf("%s,",t->name);
}
void preorder(struct playerProfile *t)
{
	printf("%s,",t->name);
	inorder(t->left);
	inorder(t->right);
}
 

		
