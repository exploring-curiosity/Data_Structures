#include"BStimpl.h"
void main()
{
	
	struct playerProfile *t,*r;
	char s[100];
	int ch;
	/*	
	t=insert(t,"kamal");
	t=insert(t,"ram");
	t=insert(t,"guru");
	t=Delete(t,"ram");
	display(t,0);*/
	printf("\n");
	do
	{
		printf("1.Insert\n2.Delete\n3.Find\n4.display\n5.Inorder\n6.Preorder\n7.Postorder\n8.exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :printf("Enter Name:");
				scanf(" %s",s);
				//printf("Inserting");
				t=insert(t,s);
				break;
			case 2 :printf("Enter Name:");	
				scanf(" %s",s);
				t=Delete(t,s);
				break;
			case 3 :printf("Enter Name:");	
				scanf(" %s",s);
				r=find(t,s);
				printf("%s,%s,%s\n",r->name,r->right->name,r->left->name);
				break;
			case 4 :display(t,0);
				break;
			case 5 :inorder(t);
				break;
			case 6 :preorder(t);
				break;
			case 7 :postorder(t);
				break;

		}
	}while(ch!=8);
}		
