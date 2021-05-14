#include<stdio.h>
#define sizemax 100
typedef struct
{
	int regno;
	char name[20];
	float m1,m2,m3,total;
	char res;
}student;
typedef struct
{
	student a[100];
	int size;
}listADT;
void initialize(listADT l)
{
	l.size=0;
}
void insertfront(listADT l,student s)
{
	if(l.size==sizemax)
	{
		printf("not enough space\n");
	}
	else
	{
		int i;
		for(i=l.size-1;i>=0;i--)
		{
			l.a[i+1]=l.a[i];
		}
		l.a[0]=s;
		l.size++;
	}
}
void insertend(listADT l,student s)
{
	if(l.size==sizemax)
	{
		printf("not enough space\n");
	}
	else
	{
		l.a[l.size]=s;
		l.size++;
	}
}
student searchregno(listADT l,int reg)
{
	int i;
	for(i=0;i<l.size;i++)
	{
		if(l.a[i].regno==reg)
			return l.a[i];
	}
}
void insertregno(listADT l,int reg,student s)
{
	int i,regpos;
	for(i=0;i<l.size;i++)
	{
		if(l.a[i].regno==reg)
			break;
	}
	regpos=i;
	if(regpos<l.size)
	{
		for(i=l.size-1;i>regpos;i--)
		{
			l.a[i+1]=l.a[i];
		}
		l.a[regpos+1]=s;
	}
}
void listregno(listADT l,int regno)
{
	student s;
	s=searchregno(l,regno);
	printf("name:%s\nmarks 1:%f 2:%f 3:%f total:%f \n result : %c\n",s.name,s.m1,s.m2,s.m3,s.total,s.res);
}
void delete(listADT l,int reg)
{
	if(l.size==0)
	{
		printf("the list is empty\n");
		return;
	}
	student s;
	s=searchregno(l,reg);
	if(s.regno>0)
	{
		printf("name:%s\nmarks 1:%f 2:%f 3:%f total:%f \n result : %c\n",s.name,s.m1,s.m2,s.m3,s.total,s.res);
		int i,regpos;
		for(i=0;i<l.size;i++)
		{
			if(l.a[i].regno==reg)
				break;
		}
		regpos=i;
		if(regpos<l.size)
		{
			for(i=regpos;i<l.size-1;i++)
			{
				l.a[i]=l.a[i+1];
			}
		}
		l.size--;
	}
}
void computeresult(listADT l)
{
	int i;
	for(i=0;i<l.size;i++)
	{
		l.a[i].total=l.a[i].m1+l.a[i].m2+l.a[i].m3;
		if((l.a[i].m1>=50)&&(l.a[i].m2>=50)&&(l.a[i].m3>=50))
		{
			l.a[i].res='P';
		}
		else
			l.a[i].res='F';
	}
}
void listresult(listADT l)
{
	int i,j=1;
	for(i=0;i<l.size;i++)
	{
		if(l.a[i].res=='P')
		{
			printf("%d. %s\n",j,l.a[i].name);
			j++;
		}
	}
}
student getentry()
{
	student s;
	printf("enter student name:");
	scanf("%s",s.name);
	printf("enter student regno:");
	scanf("%d",&s.regno);
	printf("enter student mark 1:");
	scanf("%d",&s.m1);
	printf("enter student mark 2:");
	scanf("%d",&s.m2);
	printf("enter student mark 3:");
	scanf("%d",&s.m3);
	return s;	
}
int listclass(listADT l)
{
	int i,j=0;
	for(i=0;i<l.size;i++)
	{
		if(l.a[i].res=='P')
		{
			j++;
		}
	}
	return j;
}

void main()
{
	char choice;
	char ch;
	student s;
	int reg;
	listADT l;
	initialize(l);
	do
	{
		printf("choose operation\n\n 1.insert front \n 2.insert end \n 3.insert after regno \n 4.search by regno \n 5.delete \n 6.comput result\n 7.show result your choice :");
		scanf(" %c",&choice);
		switch(choice)
		{
			case '1' : 
					s=getentry();
					insertfront(l,s);
					break;
			case '2' : 	s=getentry();
					insertend(l,s);
					break;
			case '3' : 
					s=getentry();
					printf("enter reg no:");
					scanf("%d",&reg);
					insertregno(l,reg,s);
					break;
			case '4' : 
					printf("enter reg no:");
					scanf("%d",&reg);
					searchregno(l,reg);
					break;						
		}
		printf("do u want to continue [y/n]");
		scanf(" %c",&ch);
	}while(ch=='y');
}