
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "list_API.h"




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
