#include"Sortintfc.h"
numberADT* init(int N)
{
	numberADT *na;
	na=(numberADT*)malloc(sizeof(numberADT));
	na->a=(int*)malloc(sizeof(int)*N);
	na->size=N;
	return na;
}
void insertElements(numberADT *N, int x[])
{
	int i;
	for(i=0;i<N->size;i++)
	{
		N->a[i]=x[i];
	}
}
void selSort(numberADT *N)
{
	int i,j,small,pos;
	display(N);
	for(i=0;i<N->size;i++)
	{
		small=N->a[i];
		pos=i;
		for(j=i+1;j<N->size;j++)
		{
			if(N->a[j]<small)
			{
				small=N->a[j];
				pos=j;
			}
		}
		N->a[pos]=N->a[i];
		N->a[i]=small;
		display(N);
	}
}
void shellSort(numberADT *N)
{
	int vs[N->size];
	int i,j,gap;
	gap=N->size/2;
	display(N);
	for(i=gap;i>1;i--)
	{
		for(j=0;j+i<N->size;j++)
		{
			if(vs[j]==1)
			{
				j+=i-1;
				continue;
			}
			else if(N->a[j]>N->a[i+j])
			{
				int temp=N->a[j];
				N->a[j]=N->a[j+i];
				N->a[i+j]=temp;
				vs[j]=1;
				vs[j+i]=1;
			}
		}
		display(N);
	}
	printf("Sorting\n");
	selSort(N);
}

void display(numberADT *N)
{
	int i;
	for(i=0;i<N->size;i++)
	{
		printf("%d\t",N->a[i]);
	}
	printf("\n");
}