#ifndef _TYPES_H_
#define _TYPES_H_

typedef int Type;

typedef struct node
{
	Type data;
	struct node *next;
} Node;


typedef struct stack
{
	Node *last;
	int size;

	void (*push)(struct stack *, Node *);
	Type (*pop)(struct stack *);
	Type (*top)(struct stack *);
	int (*is_empty)(struct stack *);
	void (*print)(struct stack *);
} Stack;

#endif
