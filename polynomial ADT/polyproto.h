#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int expo,coeff;
}term;
struct poly
{
	term t;
	struct poly *next;
};
struct poly * order(struct poly *p3);
int evaluate(struct poly *p,int x);

int polyDegree(struct poly *p);
struct poly * polymul(struct poly *p1,struct poly *p2);
struct poly * polyadd(struct poly *p1,struct poly *p2);
void insertAfterTerm(struct poly *p,term x,int exp);
term getterm();
void display(struct poly *p);
void insertEnd(struct poly *p,term x);
void insertFront(struct poly *p,term x);
struct poly * initialize(struct poly *p);