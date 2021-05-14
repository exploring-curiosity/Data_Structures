#include"hashSCintfc.h"
HashTableADT* init(int T)
{
	int i;	
	HashTableADT *h;
	h=(HashTableADT*)malloc(sizeof(HashTableADT));
	h->TS=T;
	for(i=0;i<T;i++)
	{
		h->a[i]=(node*)malloc(sizeof(node));
		h->a[i]->next=NULL;
	}
	return h;
}
void insertElement(HashTableADT *H, int x)
{
	int i;
	i=x%H->TS;
	node *temp;
	temp=(node*)malloc(sizeof(node));	
	temp->ele=x;
	temp->next=H->a[i]->next;
	H->a[i]->next=temp;
}
void searchElement(HashTableADT *H, int key) 
{
	int i=key%H->TS;
	node *t;
	t=H->a[i]->next;i=-1;
	while(t!=NULL)
	{
		if(t->ele==key)
		{
			i++;
			break;
		}
		t=t->next;
	}
	if(i>=0)
	{
		printf("Element found\n");
	}
	else
	printf("element not found\n");
}
void displayHT(HashTableADT *H)
{
	node *t;
	int i;
	for(i=0;i<H->TS;i++)
	{
		t=H->a[i]->next;
		printf("%d->",i);
		while(t!=NULL)
		{
			printf("%d\t",t->ele);
			t=t->next;
		}
		printf("\n");	
	}
}
