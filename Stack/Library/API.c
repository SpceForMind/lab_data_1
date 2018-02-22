
#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "API.h"

int PointerIsNull(const void *p)
{
	if(p == NULL)
	{
		printf("NULL pointer!\n");
		return 1;
	}
	else
		return 0;
}

int IsEmpty(Stack *pstack)
{
	return !pstack->size;
}


Node *MakeNode(Type data)
{
	Node *new_node = (Node *)malloc(sizeof(Node));

	if(new_node == NULL)
	{
		fprintf(stderr, "No memory!");
		exit(1);
	}

	new_node->data = data;
	new_node->next = NULL;
	
	return new_node;
}


void Push(Stack *pstack, Node *new_node)
{
	if(PointerIsNull(pstack) || PointerIsNull(new_node))
		return;

	new_node->next = pstack->last;
	pstack->last = new_node;
	++pstack->size;
}


Type Pop(Stack *pstack)
{
	if(PointerIsNull(pstack))
	{
		fprintf(stderr, "NULL pointer on stack!");
		exit(1);
	}

	if(pstack->is_empty(pstack))
	{
		printf("Pop: Stack is empty!");
		exit(2);
	}

	Node *time_node = pstack->last;
	Type top_data = pstack->last->data;

	pstack->last = pstack->last->next;
	free(time_node);
	--pstack->size;
	time_node = NULL;
	
	return top_data;
}


Type Top(Stack *pstack)
{
	if(PointerIsNull(pstack))
	{
		fprintf(stderr, "NULL pointer on stack!");
		exit(1);
	}
	
	if(pstack->is_empty(pstack))
	{
		printf("Top: Stack is empty!");
		exit(2);
	}

	return pstack->last->data;
}


void PrintStack(Stack *pstack)
{
	if(PointerIsNull(pstack))
		return;
	
	Node *current_node = pstack->last;

	for(int i = 0; i < pstack->size; ++i)
	{
		printf("[%d]\n", current_node->data);
		current_node = current_node->next;
	}
}

void Initialize(Stack *pstack)
{
	if(PointerIsNull(pstack))
		return;

	pstack->last = NULL;
	pstack->size = 0;

	pstack->push = Push;
	pstack->pop = Pop;
	pstack->top = Top;
	pstack->is_empty = IsEmpty;
	pstack->print = PrintStack;
}

