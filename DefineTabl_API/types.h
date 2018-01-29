#ifndef _TYPES_H_
#define _TYPES_H_

#define MAXWORD 40

typedef struct node
{
	struct node *next;
	char name[MAXWORD];
	char defn[MAXWORD];
} Node;


typedef struct list
{
	Node *front;
	int size;
} List;

#endif
