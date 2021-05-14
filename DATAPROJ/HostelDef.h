struct node
{
	char name[50];
	char fathername[50];
	char dept[5];
	int year;
	int roomno;
	char address[100];
	char phoneno[50];
	char typeofhostel[50];
	char mode[20];
	struct node *next;
};

struct queue
{
	struct node stu;
	struct queue *next;
};

struct node *shared = NULL;
struct node *single = NULL;
struct node *inter = NULL;
struct queue *q1 = NULL;
struct queue *q2 = NULL;
struct queue *q3 = NULL;
struct node *q4;

struct node *createemptylist(struct node *);
struct node *insert(struct node *p, char a[], char b[], char c[], char e[], char f[], int d, char g[], char h[], int room);
int delete (struct node *hd, char name[50], char fname[50]);
void display(struct node *hd);
int search(struct node *hd, char name[50], char fname[50]);
struct queue *createqueue(struct queue *q);
struct node *dequeue(struct queue *q);
void enqueue(struct queue *q, char qname[], char qfname[], char dept[], int d, char address[], char mob[], char hostel[], char mode[], int room);
int isQEmpty(struct queue *q);