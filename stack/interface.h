#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct
{
	int size,top;
	char a[100];
}stack;
int isempty(stack *s);
int isfull(stack *s);
stack * initialize();
void push(stack *s,char c);
void pop(stack *s);
void display(stack *s);
void convert(char a[100],char b[100]);
int precedence(char s);
int isopr(char s);
int isdigi(char s);
void popv(stack *s);
int bc(char a,int x,int y);
int evaluate(char b[100]);

