#ifndef _TYPES_
#define _TYPES_

typedef struct node
{
	char key_word[9];
	int count;
} Node;


typedef struct key_value
{
	Node **front;
	int count_word;

	void (*print)(struct key_value *);
	void (*add)(struct key_value *, Node *);
	Node *(*make_node)(char *);
} KeyValue;

#endif

