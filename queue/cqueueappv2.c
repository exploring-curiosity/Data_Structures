

#include"cqueuev2.h"
void main()
{
	queue *q1,*q2;
	int sm,k=0;
	job s;
	printf("enter the size : ");
	scanf("%d",&sm);
	q1=initialize(sm);
	q2=initialize(sm);
	int ch;
	do
	{
		printf("1.Insert \n2.Display \n3.exit\n");
		printf("your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :printf("enter Burst time: ");
				scanf("%d",&sm);
				s.jobno=k;
				k++;
				s.bursttime=sm;
				if(queuetime(q1)<queuetime(q2))
				enqueue(q1,s);
				else
				enqueue(q2,s);
				break;
			case 2 :display(q1);
				printf("\n");
				display(q2);
				break;
			case 3 :break;
			default:printf("Invalid \n");
		} 
	}while(ch!=3);
}
