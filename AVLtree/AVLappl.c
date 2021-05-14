#include"AVLimpl.h"
void main()
{
	struct tree *t;
	t=NULL;
	t=insert(t,34);
	t=insert(t,14);	t=insert(t,4);	t=insert(t,24);	t=insert(t,32);	t=insert(t,37);	
	display(t,0);

}