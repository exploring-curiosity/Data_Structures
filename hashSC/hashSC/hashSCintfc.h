#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int ele;
	struct node *next;
}node;
typedef struct
{
	node *a[100];
	int TS;
}HashTableADT;	
HashTableADT* init(int T);
void insertElement (HashTableADT *H, int x);
void searchElement(HashTableADT *H, int key) ;
void displayHT(HashTableADT *H);

