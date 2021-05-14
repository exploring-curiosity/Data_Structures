#include"DLimpl.h"
#include<time.h>
void main()
{
	srand(time(0));
	struct dbl *head,*tail;
	head=initialize();
	tail=initialize();
	head->next=tail;
	tail->prev=head;
	personal q;
	ratio r;
	char rep,loc[100];
	int pin,ch;	
	int i,min;
	do
	{
		printf("1.insert front \n2.insert end \n3.insert after pin \n4.display senior persons \n5.display locale persons \n6.sort\n7.display\n8.ratio\nchoice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :getinfo(&q);
					insertfront(head,tail,q);
					break;
			case 2 :getinfo(&q);
					insertend(head,tail,q);
					break;
			case 3 :printf("Enter the PIN :");
					scanf("%d",&pin);
					getinfo(&q);
					insertpin(head,tail,q,pin);
					break;
			case 4 :display(seniorperson(head));
					break;
			case 5 :printf("Enter location : ");
					scanf("%s",loc);
					display(locateperson(head,loc));
					break;
			case 6 :sort(head,tail);break;
			case 7 :display(head);break;
			case 8 :r=adultperson(head);
					if(r.m>r.f)
					min=r.f;
					else
					min=r.m;
					for(i=2;i<=min;i++)
					{
						if(r.m%i==0&&r.f%i==0)
						{
							r.m/=i;
							r.f/=i;
						}
					}
					printf("the ratio is : %d/%d\n",r.m,r.f);
					break;
			default:printf("Invalid statement\n");
		}
		printf("\ndo you want to continue(y/n)?  : ");
		scanf(" %c",&rep);
	}while(rep=='y');
}
/*

PS F:\data structures\Doubly link list> ./k
1.insert front
2.insert end
3.insert after pin
4.display senior persons
5.display locale persons
6.sort
7.display
8.ratio
choice: 1
Enter the name: ram
Enter the Address: chennai
Enter the Gender: m
Enter the age : 34
Generated pin : 1098
do you want to continue(y/n)?  : y
1.insert front
2.insert end
3.insert after pin
4.display senior persons
5.display locale persons
6.sort
7.display
8.ratio
choice: 2
Enter the name: kamal
Enter the Address: chennai
Enter the Gender: m
Enter the age : 65
Generated pin : 1030
do you want to continue(y/n)?  : y
1.insert front
2.insert end
3.insert after pin
4.display senior persons
5.display locale persons
6.sort
7.display
8.ratio
choice: 3
Enter the PIN :1098
Enter the name: tina
Enter the Address: trichy
Enter the Gender: f
Enter the age : 21
Generated pin : 1176
do you want to continue(y/n)?  : y
1.insert front
2.insert end
3.insert after pin
4.display senior persons
5.display locale persons
6.sort
7.display
8.ratio
choice: 7
Name: ram
Age : 34
Address: chennai
Gender: m
Generated pin : 1098
Name: tina
Age : 21
Address: trichy
Gender: f
Generated pin : 1176
Name: kamal
Age : 65
Address: chennai
Gender: m
Generated pin : 1030

do you want to continue(y/n)?  : y
1.insert front
2.insert end
3.insert after pin
4.display senior persons
5.display locale persons
6.sort
7.display
8.ratio
choice: 4

Name: kamal
Age : 65
Address: chennai
Gender: m
Generated pin : 1030

do you want to continue(y/n)?  : y
1.insert front
2.insert end
3.insert after pin
4.display senior persons
5.display locale persons
6.sort
7.display
8.ratio
choice: 5
Enter location : chennai
Name: kamal
Age : 65
Address: chennai
Gender: m
Generated pin : 1030
Name: ram
Age : 34
Address: chennai
Gender: m
Generated pin : 1098

do you want to continue(y/n)?  : y
1.insert front
2.insert end
3.insert after pin
4.display senior persons
5.display locale persons
6.sort
7.display
8.ratio
choice: 6

do you want to continue(y/n)?  : y
1.insert front
2.insert end
3.insert after pin
4.display senior persons
5.display locale persons
6.sort
7.display
8.ratio
choice: 7
Name: tina
Age : 21
Address: trichy
Gender: f
Generated pin : 1176
Name: ram
Age : 34
Address: chennai
Gender: m
Generated pin : 1098
Name: kamal
Age : 65
Address: chennai
Gender: m
Generated pin : 1030

do you want to continue(y/n)?  : y
1.insert front
2.insert end
3.insert after pin
4.display senior persons
5.display locale persons
6.sort
7.display
8.ratio
choice: 8
the ratio is : 2/1

do you want to continue(y/n)?  : n
*/