#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int *a;
	int size;
}numberADT;
numberADT* init(int N);
void insertElements(numberADT *N,int x[]);
void selSort(numberADT *N);
void shellSort(numberADT *N);
void display(numberADT *N); 