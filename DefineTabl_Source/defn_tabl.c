
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


void InitializeList(List *plist)
{
	if(PointerIsNull(plist))
		return;

	plist->front = NULL;
	plist->size = 0;
}


void PrintList(List *plist)
{
	if(PointerIsNull(plist) || PointerIsNull(plist->front))
		return;

	Node *print_node = plist->front;

	for(int i = 0; i < plist->size; ++i)
	{
		printf("%s %s\n", print_node->name, print_node->defn);
		print_node = print_node->next;
	}

	printf("--------------\n");
}

Node *MakeNode(const char *name, const char *defn)
{
	if(PointerIsNull(name) || PointerIsNull(defn))
		return NULL;
		

	Node *new_node = (Node *)malloc(sizeof(Node));

	if(PointerIsNull(new_node))
		return NULL;

	strncpy(new_node->name, name, strlen(name) + 1);
	strncpy(new_node->defn, defn, strlen(defn) + 1);
	new_node->next = NULL;

	return new_node;
}


void AddNode(Node *new_node, List *plist)
{
	if(PointerIsNull(new_node), PointerIsNull(plist))
		return ;

	if(plist->front == NULL)
	{
		plist->front = new_node;
		++plist->size;
	}
	else
	{
		Node *time_node = plist->front;
		
		while(time_node->next!= NULL)
		{
			if(strncmp(time_node->name, new_node->name, strlen(time_node->name)) == 0)
			{
				strncpy(time_node->defn, new_node->defn, strlen(new_node->defn) + 1);
				return;
			}
		
			time_node = time_node->next;	
		}
		
		if(strncmp(time_node->name, new_node->name, strlen(new_node->name) + 1) == 0)
		{
				strncpy(time_node->defn, new_node->defn, strlen(new_node->defn + 1));
				return;
		}
	
				time_node->next = new_node;
				++plist->size;
	}
}


void DeleteNode(char *name, List *plist)
{
	if(PointerIsNull(name) || PointerIsNull(plist))
		return;
	if(PointerIsNull(plist->front))
		return;

	Node **current_node = &plist->front;

	while((*current_node)!= NULL)
	{
		if(strncmp((*current_node)->name, name, strlen(name) + 1) == 0)
		{
			Node *time_node = *current_node;
			(*current_node) = (*current_node)->next;
			free(time_node);
			time_node = NULL;
			--plist->size;
			return;
		}
		current_node = &(*current_node)->next;
	}
}


int main()
{
	List list;
	
	InitializeList(&list);
	
	int n;
	if(scanf("%d\n", &n)!= 1)
		return 0;

	for(int i = 0; i < n; ++i)
	{
		char *name = (char *)malloc(sizeof(char) * MAXWORD);
		char *defn = (char *)malloc(sizeof(char) * MAXWORD);
		
		fgets(name, MAXWORD, stdin);
		fgets(defn, MAXWORD, stdin);
		(*strstr(name, "\n")) = 0;
		(*strstr(defn, "\n")) = 0;

		Node *new_node = MakeNode(name, defn);
		AddNode(new_node, &list);
	}

	PrintList(&list);
	DeleteNode("HASH", &list);
	PrintList(&list);

	return 0;
}
