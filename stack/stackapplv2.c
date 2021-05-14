#include"stackimpl.h"
void main()
{
	char s[100],s1[100];
	printf("enter the expression\n");
	scanf(" %s",s);
	convert(s,s1);
	printf("%s\n",s1);
}
