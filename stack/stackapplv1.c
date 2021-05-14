#include"stackimpl.h"
void main()
{
	stack *s;
	s=initialize();
	push(s,'a');
	push(s,'d');
	push(s,'c');
	push(s,'b');
	display(s);
	pop(s);
	pop(s);
	display(s);
}
