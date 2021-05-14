#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char p;
	struct node *r,*l;
};
typedef struct
{
	int size,top;
	struct node *a[100];
}stack;
typedef struct ExpTree
{
	char infix[100],postfix[100];
	int value;
	stack *s;
}ExpTree;

ExpTree* treeinit();

int isempty(stack *s);
int isfull(stack *s);
stack* initialize();
void push(stack *s,struct node *c);
struct node* nodeinit(char c);
void display(stack *s);
void convert(ExpTree *t);
int precedence(char s);
int isopr(char s);
int isdigi(char s);
struct node* popv(stack *s);
int bc(char a,int x,int y);
int process(struct node *n);