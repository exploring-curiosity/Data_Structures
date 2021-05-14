#include"BFSimpl.h"
void main()
{
	char s[100],d[100];
	cityADT *c;
	int ch;
	do
	{
		printf("choose:\n1.create\n2.display\n3.BFS output\n4.check connectivity\n5.exit\nyour choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :c=create(c);
					break;
			case 2 :disp(c);
					break;
			case 3 :BFS(c);break;
			case 4 :printf("enter source and destination cities\n");
					scanf("%s",s);
					scanf("%s",d);
					if(checkConnectivity(c,s,d)==1)
					printf("they are connected\n");
					else
					printf("they are not connected\n");
					break;
			case 5 :break;
			default:printf("Invalid");
		}
	}while(ch!=5);
}
/*
cs1173@jtl-16:~$ gcc BFSappl.c -o k
cs1173@jtl-16:~$ ./k
choose:
1.create
2.display
3.BFS output
4.check connectivity
5.exit
your choice:1
Enter no of citites : 2
enter the cities
chennai
salem
Enter Neighbours of chennai:
Are there any neighbours?y/n : y
salem
city found at : 1 
Are there any more neighbours?y/n : n
Enter Neighbours of salem:
Are there any neighbours?y/n : y
chennai
city found at : 0 
Are there any more neighbours?y/n : n
choose:
1.create
2.display
3.BFS output
4.check connectivity
5.exit
your choice:2
   	0	1
   __________________

0 |	0	1   |

1 |	1	0   |
   __________________
choose:
1.create
2.display
3.BFS output
4.check connectivity
5.exit
your choice:3
chennai	salem	,,
choose:
1.create
2.display
3.BFS output
4.check connectivity
5.exit
your choice:4
enter source and destination cities
chennai
salem
source found 
they are connected
choose:
1.create
2.display
3.BFS output
4.check connectivity
5.exit
your choice:5

*/

