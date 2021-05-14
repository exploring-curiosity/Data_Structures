#include"implementation.h"
void main()
{
	term t;
	struct poly *p1,*p2,*p3;
	int ch,x,res;
	char rep;
	p1=initialize(p1);
	p2=initialize(p2);
	p3=initialize(p3);

	do
	{
		printf("Choose option \n 1.Addition \n 2.Multiplication \n 3.evaluate\n your choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :p1=initialize(p1);
					p2=initialize(p2);
					p3=initialize(p3);
					getpoly(p1);
					getpoly(p2);
					p3=order(polyadd(p1,p2));
					display(p1);
					display(p2);
					display(p3);

					break;
			case 2 :p1=initialize(p1);
					p2=initialize(p2);
					p3=initialize(p3);
					getpoly(p1);
					getpoly(p2);
					p3=polymul(p1,p2);
					display(p1);
					display(p2);
					display(p3);
					break;
			case 3 :p1=initialize(p1);
					p2=initialize(p2);
					p3=initialize(p3);
					getpoly(p1);
					printf("enter the value of x : ");
					scanf("%d",&x);
					res=evaluate(p1,x);
					printf("the result is : %d\n",res);
					break;
					
			default:printf("option Mismatch!!!\n");
		}printf("do you want to continue(y/n) : ");
		scanf(" %c",&rep);
	}while(rep=='y');
}
/*

PS F:\data structures\assignment> gcc application.c -o k
PS F:\data structures\assignment> ./k
Choose option
 1.Addition
 2.Multiplication
 3.evaluate
 your choice :1
Enter Coefficient:3
Enter its Exponent:2
How do you want to insert it?
1.Insert front
 2. Insert End
 3.Insert After a Exponent 1
Insert another term (1/0) : 1
Enter Coefficient:2
Enter its Exponent:1
How do you want to insert it?
1.Insert front
 2. Insert End
 3.Insert After a Exponent 1
Insert another term (1/0) : 1
Enter Coefficient:1
Enter its Exponent:0
How do you want to insert it?
1.Insert front
 2. Insert End
 3.Insert After a Exponent 1
Insert another term (1/0) : 0
Enter Coefficient:3
Enter its Exponent:2
How do you want to insert it?
1.Insert front
 2. Insert End
 3.Insert After a Exponent 1
Insert another term (1/0) : 1
Enter Coefficient:2
Enter its Exponent:1
How do you want to insert it?
1.Insert front
 2. Insert End
 3.Insert After a Exponent 1
Insert another term (1/0) : 1
Enter Coefficient:1
Enter its Exponent:0
How do you want to insert it?
1.Insert front
 2. Insert End
 3.Insert After a Exponent 1
Insert another term (1/0) : 0
1^0 + 2^1 + 3^2
1^0 + 2^1 + 3^2
6^2 + 4^1 + 2^0
do you want to continue(y/n) : y
Choose option
 1.Addition
 2.Multiplication
 3.evaluate
 your choice :2
Enter Coefficient:3
Enter its Exponent:2
How do you want to insert it?
1.Insert front
 2. Insert End
 3.Insert After a Exponent 2
Insert another term (1/0) : 1
Enter Coefficient:3
Enter its Exponent:1
How do you want to insert it?
1.Insert front
 2. Insert End
 3.Insert After a Exponent 2
Insert another term (1/0) : 0
Enter Coefficient:3
Enter its Exponent:2
How do you want to insert it?
1.Insert front
 2. Insert End
 3.Insert After a Exponent 2
Insert another term (1/0) : 1
Enter Coefficient:3
Enter its Exponent:1
How do you want to insert it?
1.Insert front
 2. Insert End
 3.Insert After a Exponent 1
Insert another term (1/0) : 0
3^2 + 3^1
3^1 + 3^2
9^4 + 18^3 + 9^2
do you want to continue(y/n) : y
Choose option
 1.Addition
 2.Multiplication
 3.evaluate
 your choice :3
Enter Coefficient:3
Enter its Exponent:2
How do you want to insert it?
1.Insert front
 2. Insert End
 3.Insert After a Exponent 2
Insert another term (1/0) : 1
Enter Coefficient:4
Enter its Exponent:1
How do you want to insert it?
1.Insert front
 2. Insert End
 3.Insert After a Exponent 3
enter the exponent: 2
Insert another term (1/0) : 1
Enter Coefficient:2
Enter its Exponent:0
How do you want to insert it?
1.Insert front
 2. Insert End
 3.Insert After a Exponent 1
Insert another term (1/0) : 0
enter the value of x : 1
the result is : 9
do you want to continue(y/n) : n

*/