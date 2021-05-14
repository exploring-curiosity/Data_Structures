#include"cqueue.h"
void main()
{
	queue *q;
	int sm;
	printf("enter the size : ");
	scanf("%d",&sm);
	q=initialize(sm);
	int ch;
	do
	{
		printf("1.Insert \n2.Delete \n3.Display \n4.exit\n");
		printf("your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :printf("enter element : ");
				scanf("%d",&sm);
				enqueue(q,sm);
				break;
			case 2 :sm=dequeue(q);
				if(sm!=-1)
				printf("element : %d\n",sm);
				break;
			case 3 :display(q);
				break;
			case 4 :break;
			default:printf("Invalid \n");
		} 
	}while(ch!=4);
}
