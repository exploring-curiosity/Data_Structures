#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
	char name[20];
	int age;
	char address[30];
	char gender;
	int no;
}personal;
typedef struct
{
	int m,f;
}ratio;
struct dbl
{
	personal p;
	struct dbl *next,*prev;
};
struct dbl * initialize();
void insertfront(struct dbl *h,struct dbl *t,personal a);
void display(struct dbl *h);
void disp(personal p);
void getinfo(personal *p);
