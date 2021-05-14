struct node *createemptylist(struct node *h)
{
	h = (struct node *)malloc(sizeof(struct node));
	h->next = NULL;
	return h;
}

struct node *insert(struct node *p, char a[], char b[], char c[], char e[], char f[], int d, char g[], char h[], int room)
{
	struct node *x, *y;
	if (p == NULL)
	{
		x = (struct node *)malloc(sizeof(struct node));
		strcpy(x->name, a);
		strcpy(x->fathername, b);
		strcpy(x->dept, c);
		x->year = d;
		x->roomno = room;
		strcpy(x->address, e);
		strcpy(x->phoneno, f);
		strcpy(x->typeofhostel, g);
		strcpy(x->mode, h);
		p = x;
		x->next = NULL;
	}
	else
	{
		y = p;
		while (y->next != NULL)
			y = y->next;
		x = (struct node *)malloc(sizeof(struct node));
		strcpy(x->name, a);
		strcpy(x->fathername, b);
		strcpy(x->dept, c);
		x->year = d;
		x->roomno = room;
		strcpy(x->address, e);
		strcpy(x->phoneno, f);
		strcpy(x->typeofhostel, g);
		strcpy(x->mode, h);
		x->next = NULL;
		y->next = x;
	}
	return p;
}

int isEmpty(struct node *hd)
{
	return(hd->next == NULL);
}

int delete (struct node *hd, char name[50], char fname[50])
{
	int rno = 0;
	if(!isEmpty(hd))
	{
		int checkdel = 10;
		struct node *p;
		p = (struct node *)malloc(sizeof(struct node));
		p = hd;
		struct node *temp = (struct node *)malloc(sizeof(struct node));
		while (p->next != NULL)
		{
			int a = strcmp(p->next->name, name);
			if (a == 0)
			{
				temp = p->next;
				checkdel = 1;
				rno = temp->roomno;
				p->next = p->next->next;
				free(temp);
				printf("\nRoom Successfully vacated.\n");
			}
			else
				p = p->next;
		}
	}
	return rno;
}

void display(struct node *hd)
{
	struct node *p;
	p = (struct node *)malloc(sizeof(struct node));
	p = hd->next;
	while (p != NULL)
	{
		printf("\nName              : %s", p->name);
		printf("\nFather\'s Name     : %s", p->fathername);
		printf("\nDepartment        : %s\n", p->dept);
		if(!strcmp(p->typeofhostel, "Single"))
			printf("Room Number       : A-%d", p->roomno);
		else if(!strcmp(p->typeofhostel, "Shared"))
			printf("Room Number       : B-%d", p->roomno);
		else if(!strcmp(p->typeofhostel, "International"))
			printf("Room Number       : I-%d", p->roomno);
		printf("\nAddress           : %s", p->address);
		printf("\nPhone Number      : %s", p->phoneno);
		printf("\nYear              : %d", p->year);
		printf("\nHostel Type       : %s", p->typeofhostel);
		printf("\nMode of Admission : %s\n", p->mode);
		p = p->next;
	}
}

void writeToFile(FILE *fp, struct node *hd)
{
	struct node *p;
	p = (struct node *)malloc(sizeof(struct node));
	p = hd->next;
	while (p != NULL)
	{
		fprintf(fp, "\nName              : %s\nFather\'s Name     : %s\nDepartment        : %s\n", p->name, p->fathername, p->dept);
		if(!strcmp(p->typeofhostel, "Single"))
			fprintf(fp, "Room Number       : A-%d\n", p->roomno);
		else if(!strcmp(p->typeofhostel, "Shared"))
			fprintf(fp, "Room Number       : B-%d\n", p->roomno);
		else if(!strcmp(p->typeofhostel, "International"))
			fprintf(fp, "Room Number       : I-%d\n", p->roomno);
		fprintf(fp, "Address           : %s\nPhone Number      : %s\nYear              : %d\n", p->address, p->phoneno, p->year);
		fprintf(fp, "Hostel Type       : %s\nMode of Admission : %s\n", p->typeofhostel, p->mode);
		p = p->next;
	}
}

void writeWaitToFile(FILE *fp, struct queue *q)
{
	if(!isQEmpty(q))
	{
		struct queue *new = (struct queue*)malloc(sizeof(struct queue));
		new = q->next;
		int i=0;
		while(new!=NULL)
		{
			i++;
			fprintf(fp, "\nName              : %s\nFather\'s Name     : %s\nDepartment        : %s\nYear              : %d\nAddress           : %s\nPhone Number      : %s\n", new->stu.name, new->stu.fathername, new->stu.dept, new->stu.year, new->stu.address, new->stu.phoneno);
			fprintf(fp, "Hostel Type       : %s\nMode of Admission : %s\nWaiting List No.  : %d\n", new->stu.typeofhostel, new->stu.mode, i);
			new = new->next;
		}
	}
	else
		printf("\nWaiting List empty!\n");
}

int search(struct node *hd, char name[50], char fname[50])
{
	struct node *x;
	int check = 0;
	x = hd;
	while (x != NULL)
	{
		if (strcmp(x->name, name) == 0 && strcmp(x->fathername, fname) == 0)
		{
			printf("\n------> Details of the Student <------\n");
			printf("\nName              : %s\nFather\'s Name     : %s\nDepartment        : %s\n", x->name, x->fathername, x->dept);
			if(!strcmp(x->typeofhostel, "Single"))
				printf("Room Number       : A-%d\n", x->roomno);
			else if(!strcmp(x->typeofhostel, "Shared"))
				printf("Room Number       : B-%d\n", x->roomno);
			else if(!strcmp(x->typeofhostel, "International"))
				printf("Room Number       : I-%d\n", x->roomno);
			printf("Year              : %d\nAddress           : %s\nPhone Number      : %s\n", x->year, x->address, x->phoneno);
			printf("Hostel Type       : %s\nMode of Admission : %s\n", x->typeofhostel, x->mode);
			printf("\n--------------------------------------\n");
			check = 1;
		}
		x = x->next;
	}
	if (check != 0)
		return 1;
	else
		return 0;
}

int isQEmpty(struct queue *q)
{
	return (q->next == NULL);
}

struct queue *createqueue(struct queue *q)
{
    q = (struct queue*)malloc(sizeof(struct queue));
    q->next = NULL;
    return q;
}

void displayQ(struct queue *q)
{
	if(!isQEmpty(q))
	{
		struct queue *new = (struct queue*)malloc(sizeof(struct queue));
		new = q->next;
		int i=0;
		while(new!=NULL)
		{
			i++;
			printf("\nName              : %s\nFather\'s Name     : %s\nDepartment        : %s\nYear              : %d\nAddress           : %s\nPhone Number      : %s\n", new->stu.name, new->stu.fathername, new->stu.dept, new->stu.year, new->stu.address, new->stu.phoneno);
			printf("Hostel Type       : %s\nMode of Admission : %s\nWaiting List No.  : %d\n", new->stu.typeofhostel, new->stu.mode, i);
			new = new->next;
		}
	}
	else
		printf("\nWaiting List empty!\n");
}

void enqueue(struct queue *q, char qname[], char qfname[], char dept[], int d, char address[], char mob[], char hostel[], char mode[], int room)
{
	struct queue *new = (struct queue *)malloc(sizeof(struct queue));
	strcpy(new->stu.name, qname);
	strcpy(new->stu.fathername, qfname);
	strcpy(new->stu.dept, dept);
	new->stu.year = d;
	new->stu.roomno = room;
	strcpy(new->stu.address, address);
	strcpy(new->stu.phoneno, mob);
	strcpy(new->stu.typeofhostel, hostel);
	strcpy(new->stu.mode, mode);
	new->next = NULL;

	if (q->next != NULL)
	{
		struct queue *temp = (struct queue *)malloc(sizeof(struct queue));
		temp = q->next;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	else
		q->next = new;
}

struct node* dequeue(struct queue *q)
{
	if(!isQEmpty(q))
	{
		struct queue *new = (struct queue*)malloc(sizeof(struct queue));
		new = q->next;
		q->next = new->next;
		struct node *stu = (struct node*)malloc(sizeof(struct node));

		strcpy(stu->name, new->stu.name);
		strcpy(stu->fathername, new->stu.fathername);
		strcpy(stu->dept, new->stu.dept);
		stu->year = new->stu.year;
		stu->roomno = new->stu.roomno;
		strcpy(stu->address, new->stu.address);
		strcpy(stu->phoneno, new->stu.phoneno);
		strcpy(stu->typeofhostel, new->stu.typeofhostel);
		strcpy(stu->mode, new->stu.mode);

		free(new);
		return stu;
	}
	else
		printf("\nWaiting List Empty!\n");
}