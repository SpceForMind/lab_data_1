#ifndef _TREE_TYPES_H_
#define _TREE_TYPES_H_

#define ERROR -1
#define MAXNAME 20

typedef struct Item
{
	char patname[MAXNAME];
	char patkind[MAXNAME];
} Item;

typedef struct trnode
{
	struct trnode *left;
	struct trnode *right;
	Item item;
} Trnode;

typedef struct Tree
{
	Trnode *root;
	int size;
} Tree;


typedef struct pare
{
	Trnode *parent;
	Trnode *child;
} Pare;
#endif
