typedef int Item;

struct Node 
{
	Item item;
	struct Node *next;
};

typedef struct Node Node;

struct Queue
{
	Node *front;
	Node *rear;
	int count;
};

typedef struct Queue Queue;


