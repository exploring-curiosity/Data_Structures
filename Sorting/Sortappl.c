#include"Sortimpl.h"
void main()
{
	int ch;
	numberADT *n;
	int x,arr[100];
	printf("Enter the Size");
	scanf("%d",&x);
	n=init(x);
	printf("Enter the Array\n");
	for(ch=0;ch<x;ch++)
	{
		scanf("%d",&arr[ch]);
	}
	insertElements(n,arr);
	printf("Selection Sort\n");
	selSort(n);
	insertElements(n,arr);
	printf("Shell Sort\n");
	shellSort(n);
}
/*
PS F:\data structures\Sorting> gcc Sortappl.c -o k
PS F:\data structures\Sorting> ./k
Enter the Size6
Enter the Array
3
4
2
1
6
5
Selection Sort
3       4       2       1       6       5
1       4       2       3       6       5
1       2       4       3       6       5
1       2       3       4       6       5
1       2       3       4       6       5
1       2       3       4       5       6
1       2       3       4       5       6
Shell Sort
3       4       2       1       6       5
1       4       2       3       6       5
1       4       2       3       6       5
Sorting
1       4       2       3       6       5
1       4       2       3       6       5
1       2       4       3       6       5
1       2       3       4       6       5
1       2       3       4       6       5
1       2       3       4       5       6
1       2       3       4       5       6
PS F:\data structures\Sorting>
*/