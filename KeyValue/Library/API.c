
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>

#include "constant.h"
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

void PrintKeyValue(KeyValue *pkeyval)
{
	if(PointerIsNull(pkeyval))
		return;
	if(PointerIsNull(pkeyval->front))
		return;

	for(int i = 0; i < pkeyval->count_word; ++i)
		printf("%s : %d\n", pkeyval->front[i]->key_word, pkeyval->front[i]->count);

	printf("---------\n");
}



Node *MakeNode(char *key_word)
{
	if(PointerIsNull(key_word))
		return NULL;

	Node *new_node = (Node *)malloc(sizeof(Node));

	if(PointerIsNull(new_node))
	{
		printf("No memory!\n");
		exit(1);
	}

	strncpy(new_node->key_word, key_word, strlen(key_word));
	new_node->count = 0;

	return new_node;
}

void AddNode(KeyValue *pkeyval, Node *new_node)
{
	if(PointerIsNull(pkeyval) || PointerIsNull(new_node))
		return;

	if(PointerIsNull(pkeyval->front))
		pkeyval->front = (Node **)malloc(MAXSIZE * sizeof(Node *));

	if(pkeyval->count_word % MAXSIZE == 0 && pkeyval->count_word!= 0)
		pkeyval->front = (Node **)realloc(&pkeyval->front[0], (pkeyval->count_word + MAXSIZE) * sizeof(Node *));	
	int i = pkeyval->count_word;

	pkeyval->front[i] = new_node;
	++pkeyval->count_word;
}


void Initialize(KeyValue *pkeyval)
{
	if(PointerIsNull(pkeyval))
		return;

	pkeyval->front = NULL;
	pkeyval->count_word = 0;
	
	pkeyval->print = PrintKeyValue;
	pkeyval->make_node = MakeNode;
	pkeyval->add = AddNode;
}


