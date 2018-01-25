
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree_types.h"
#include "tree_API.h"

#define ERROR -1
#define MAXNAME 20


int main()
{
	Tree tree;

	InitializeTree(&tree);
	
	unsigned int n;
	if(scanf("%u\n", &n)!= 1)
		return 0;
	
	for(int i = 0; i < n; ++i)
	{
		char *patname = (char *)malloc(sizeof(char) * MAXNAME);
		char *patkind = (char *)malloc(sizeof(char) * MAXNAME);
	
		if(PointerIsNull(patname) || PointerIsNull(patkind))
			break;
	
		fgets(patname, MAXNAME, stdin);
		fgets(patkind, MAXNAME, stdin);
		(*strstr(patname, "\n")) = 0;
		(*strstr(patkind, "\n")) = 0;
		
		Item *pat = (Item *)malloc(sizeof(Item));
		
		if(PointerIsNull(pat))
			break;
	
		strncpy(pat->patname, patname, strlen(patname));
		strncpy(pat->patkind, patkind, strlen(patkind));
		
		Trnode *new_node = MakeNode(pat);
		
		if(PointerIsNull(new_node))
			return 0;
		

		if(AddNode(new_node, &tree.root) == 1)
			++tree.size;
	}
	

	PrintTree(&tree);
	DeleteTree(&tree);
	PrintTree(&tree);
/*
	Item pat1 = {"John", "Fish"};
	Trnode *new_node = MakeNode(&pat1);
	Item pat2 = {"Maggy", "Fish"};
	Trnode *new_node2 = MakeNode(&pat2);	
	Item pat3 = {"Sam", "Bird"};
	Trnode *new_node3 = MakeNode(&pat3);
	Item pat4 = {"Ron", "Butterfly"};
	Trnode *new_node4 = MakeNode(&pat4);

	if(AddNode(new_node, &tree.root)!= ERROR)
		++tree.size;
	if(AddNode(new_node2, &tree.root)!= ERROR)
		++tree.size;
	if(AddNode(new_node3, &tree.root)!= ERROR)
		++tree.size;
	if(AddNode(new_node4, &tree.root)!= ERROR)
		++tree.size;

	PrintTree(&tree);
	DeleteTree(&tree);
*/

	return 0;
}
