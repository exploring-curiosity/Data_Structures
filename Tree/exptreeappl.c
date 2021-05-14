#include"exptreeimpl.h"
void main()
{
	ExpTree *tree;
	tree=treeinit();
	printf("Enter expression : ");
	scanf("%s",tree->infix);
	InfixToPostfix(tree);
	evaluate(tree);
	Display(tree);
}
	
/*
PS F:\data structures\Tree> gcc exptreeappl.c -o k
PS F:\data structures\Tree> ./k
Enter expression : 3+4/2-6*8-2+5
Infix : 3+4/2-6*8-2+5
Postfix : 342/+68*-2-5+
Value : -40
*/