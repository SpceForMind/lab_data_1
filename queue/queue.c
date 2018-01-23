
#include <stdio.h>
#include <stdlib.h>
#include "queue_struct.h"
#include "queue_API.h"
/*
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


int QueueIsEmpty(Queue *pq)
{
	return (pq->count == 0);
}


int PointerIsNull(const void *pq)
{
	if(pq == NULL)
	{
		printf("NULL pointer!\n");
		return 1;
	}
	else
		return 0;
}

void InitializeQueue(Queue *pq)
{
	if(PointerIsNull(pq))
		return;

	pq->front = pq->rear = NULL;
	pq->count = 0;
}



void AddItem(const Item item, Queue *pq)
{
	if(PointerIsNull(pq))
		return;

	Node *node = (Node *)malloc(sizeof(Node));	
	
	node->next = NULL;
	node->item = item;

	if(pq->count == 0)
		pq->front = node;
	else
	{
		Node *newitem = pq->front;
		
		if(pq->count == 1)
		{
			pq->front->next = node;
		}
		else
		{	
			while(newitem->next!= NULL)
				newitem = newitem->next;

			newitem->next = node;
		}
	}

	pq->rear = node;
	pq->count++;
}


int DeleteItem(Queue *pq)
{
	if(PointerIsNull(pq))
		return 0;

	if(QueueIsEmpty(pq))
	{
		printf("Queue is empty!\n");
		return 0;
	}

	Node *time_front = pq->front;

	pq->front = pq->front->next;	
	free(time_front);
	time_front = NULL;
	--pq->count;

	return 1;
}

void DeleteQueue(Queue *pq)
{
	if(PointerIsNull(pq))
		return;
	if(QueueIsEmpty(pq))
		return;
	
	for(int i = 0; i < pq->count; ++i)
		DeleteItem(pq);


	InitializeQueue(pq);
}


void PrintQueue(const Queue *pq)
{
	if(PointerIsNull(pq))
		return;

	Node *time_node = pq->front;

	for(int i = 0; i < pq->count; ++i)
	{
		printf("item = %d\n", time_node->item); 
		time_node = time_node->next;
	}
	printf("----------\n");
}

*/
int main()
{
	Queue queue;	

	InitializeQueue(&queue);
	
	int n;
	if(scanf("%d\n", &n) == 0)
		return 0;

	for(int i = 0; i < n; ++i)
	{
		Item num;

		if(scanf("%d", &num) == 0)
			break;

		AddItem(num, &queue);	
	}	

	PrintQueue(&queue);
	DeleteQueue(&queue);
	PrintQueue(&queue);
	AddItem(10, &queue);
	PrintQueue(&queue);

	return 0;
}
