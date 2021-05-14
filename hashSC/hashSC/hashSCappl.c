#include"hashSCimpl.h"
void main()
{
	HashTableADT *h;
	int ts,x;
	printf("Enter Table Size : ");
	scanf("%d",&ts);
	h=init(ts);
	do
	{
		printf("1.Insert element\n2.Search Element\n3.Display hashTable\n4.exit\nyour choice : ");
		scanf("%d",&ts);
		switch(ts)
		{
			case 1 :printf("Enter the Element : ");
				scanf("%d",&x);
				insertElement(h,x);
				break;
			case 2 :printf("Enter the Element : ");
				scanf("%d",&x);
				searchElement(h,x);
				break;
			case 3 :displayHT(h);
				break;
			case 4 :break;
			default:printf("INVALID \n");
		}
	}while(ts!=4); 
}
/*
cs1173@jtl-16:~$ gcc hashSCappl.c -o k
cs1173@jtl-16:~$ ./k
Enter Table Size : 4
1.Insert element
2.Search Element
3.Display hashTable
4.exit
your choice : 1
Enter the Element : 11
1.Insert element
2.Search Element
3.Display hashTable
4.exit
your choice : 1
Enter the Element : 12
1.Insert element
2.Search Element
3.Display hashTable
4.exit
your choice : 1
Enter the Element : 14
1.Insert element
2.Search Element
3.Display hashTable
4.exit
your choice : 1
Enter the Element : 13
1.Insert element
2.Search Element
3.Display hashTable
4.exit
your choice : 1
Enter the Element : 4
1.Insert element
2.Search Element
3.Display hashTable
4.exit
your choice : 1
Enter the Element : 5
1.Insert element
2.Search Element
3.Display hashTable
4.exit
your choice : 3
0->4	12	
1->5	13	
2->14	
3->11	
1.Insert element
2.Search Element
3.Display hashTable
4.exit
your choice : 2
Enter the Element : 13
Element found
1.Insert element
2.Search Element
3.Display hashTable
4.exit
your choice : 2
Enter the Element : 15
element not found
1.Insert element
2.Search Element
3.Display hashTable
4.exit
your choice : 4
*/
