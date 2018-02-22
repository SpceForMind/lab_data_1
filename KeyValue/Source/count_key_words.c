
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "types.h"
//#include "constant.h"
//#include "API.h"

#define MAXSIZE 10
#define MEMORYSIZE 100



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


char *InputCFile(char *c_text)
{
	if(PointerIsNull(c_text))
		return NULL;

	char c;
	int i = 0;

	while((c = getchar())!= EOF)
	{
		if(i % MEMORYSIZE == 0 && i!= 0)
			c_text = (char *)realloc(c_text, (i + MEMORYSIZE) * sizeof(char));

		c_text[i] = c;
		++i;
	}

	c_text[i] = '\0';

	return c_text;
}



int main()
{
	KeyValue keyval;

	Initialize(&keyval);
	PrintKeyValue(&keyval);
	
	char keytab[][10] = {"break", "while", "for", "const", "restrict", "volatile", "continue", "return", "if", "else", "static", "extern"};

	char *c_text = (char *)malloc(MEMORYSIZE * sizeof(char));
	c_text = InputCFile(c_text);

	
	for(int i = 0; i < sizeof(keytab) / sizeof(keytab[0]); ++i)
	{
		int count_key = 0;

		keyval.add(&keyval, keyval.make_node(keytab[i]));
		
		char *current_entrance = strstr(c_text, keytab[i]);
		
		while(current_entrance)
		{	
			++count_key;
			current_entrance = current_entrance + strlen(keytab[i]);
			current_entrance = strstr(current_entrance, keytab[i]);
		}

		keyval.front[i]->count = count_key;
	}	

	keyval.print(&keyval);	
		

	return 0;
}
