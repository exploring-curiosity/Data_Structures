#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct tree
{
	int ele;
	struct tree *l,*r;
	int height;
};

