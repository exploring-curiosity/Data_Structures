#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct playerProfile
{
	char name[100];
	struct playerProfile *left,*right;
};
struct playerProfile* initialize(struct playerProfile *p);
struct playerProfile* insert(struct playerProfile *p,char n[100]);
struct playerProfile* find(struct playerProfile *p,char n[100]);
void display(struct playerProfile *p,int tab);
void preorder(struct playerProfile *t);
void inorder(struct playerProfile *t);
void postorder(struct playerProfile *t);
