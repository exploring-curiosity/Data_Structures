#include"DFSimpl.h"
void main()
{
	char s[100],d[100];
	cityADT *c;
	int ch;
	do
	{
		printf("choose:\n1.create\n2.display\n3.DFS output\n4.check connectivity\n5.exit\nyour choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :c=create(c);
					break;
			case 2 :disp(c);
					break;
			case 3 :DFS(c);break;
			case 4 :printf("enter source and destination cities\n");
					scanf("%s",s);
					scanf("%s",d);
					checkConnectivity(c,s,d);
					break;
			case 5 :break;
			default:printf("Invalid");
		}
	}while(ch!=5);
}
