
int PointerIsNull(const void *p)
{
	if(p == NULL)
	{
		printf("Pointer is NULL\n");
		return 1;
	}
	else
		return 0;
}

void InitializeTree(Tree *pt)
{
	if(PointerIsNull(pt))
		return;
	
	pt->root = NULL;	
	pt->size = 0;
}


int ToLeft(const Item *pi1, const Item *pi2)
{
	int compl;
	compl = strncmp(pi1->patname, pi2->patname, MAXNAME);

	if(compl < 0)
		return 1;
	else if(compl == 0)
	{
		compl = strncmp(pi1->patkind, pi2->patkind, MAXNAME);
		
		if(compl < 0)
			return 1;
		else if(compl == 0)
		{
			fprintf(stderr, "Equivalent names!\n");
			return ERROR;
		}
		else 
			return 0;
	}	
	else
		return 0;
}


Trnode *MakeNode(const Item * restrict pi)
{
	if(PointerIsNull(pi))
		return NULL;
	
	Trnode *new_node = (Trnode *)malloc(sizeof(Trnode));
	
	if(PointerIsNull(new_node))
	{
		fprintf(stderr, "No memory!\n");
		return NULL;
	}
	else
	{
		new_node->item = *pi;
		new_node->right = new_node->left = NULL;

		return new_node;
	}	
}


int AddNode(Trnode *new_node, Trnode **root)
{
	if(PointerIsNull(new_node) || PointerIsNull(root))
		return 0;

	if(*root == NULL)
	{

		*root = new_node;
		return 1;
	}
	
	if(ToLeft(&new_node->item, &(*root)->item) == 1)
	{
		if((*root)->left == NULL)
		{
			(*root)->left = new_node;
			return 1;
		}
		else
			AddNode(new_node, &(*root)->left);
	}
	else if(ToLeft(&new_node->item, &(*root)->item) == 0)
	{
		if((*root)->right == NULL)
		{
			(*root)->right = new_node;
			return 1;
		}
		else
			AddNode(new_node, &(*root)->right);
	}
	else
	{
		fprintf(stderr, "Error of adding node!\n");
		return ERROR;
	}
}


Pare *SeekItem(Item *pi, Trnode *root)
{
	if(PointerIsNull(pi) || PointerIsNull(root))
		return NULL;

	Pare *look = (Pare *)malloc(sizeof(Pare));
	
	if(PointerIsNull(look))
	{
		fprintf(stderr, "No memory!\n");
		exit(1);
	}
	
	look->child = root;
	look->parent = NULL;

	while(look->child!=NULL)
	{
		if(ToLeft(pi, &look->child->item) == 1)
		{
			look->parent = look->child;
			look->child = look->child->left;
		}
		else if(ToLeft(pi, &look->child->item) == 0)
		{
			look->parent = look->child;
			look->child = look->child->right;
		}	
		else
			break;
	}
		return look;
}

void DeleteNode(Trnode **node)
{
	if(PointerIsNull(node))
		return;

	Trnode *time_node = *node;

	if((*node)->left == NULL)
	{
		*node = (*node)->right;
		free(time_node);
		time_node = NULL;
	}	
	else if((*node)->right == NULL)
	{
		*node = (*node)->left;
		free(time_node);
		time_node = NULL;
	}
	else
	{
		time_node = (*node)->left;
		
		while(time_node->right!= NULL)
			time_node = time_node->right;	
	
		time_node->right = (*node)->right;
		time_node = (*node);
		(*node) = (*node)->left;
		free(time_node);
		time_node = NULL;
	}
}


void DeleteItem(Item *pi, Tree *ptree)
{
	if(PointerIsNull(pi) || PointerIsNull(ptree))
			return;

	Pare *look = SeekItem(pi, ptree->root);
	
	if(PointerIsNull(look))
		return;

	if(look->child == NULL)
	{
		printf("This element impossible to deleted!\n");
		return;
	}

	if(look->parent == NULL)
		DeleteNode(&ptree->root);
	else if(look->parent->left == look->child)
		DeleteNode(&look->parent->left);
	else if(look->parent->right == look->child)
		DeleteNode(&look->parent->right);

	ptree->size--;
}


void DeleteAllNodes(Trnode *root)
{
	if(PointerIsNull(root))
		return;

	Trnode *pright;

	if(root!= NULL)
	{
		pright = root->right;
		DeleteAllNodes(root->left);
		free(root);
		DeleteAllNodes(pright);
	}
}

void DeleteTree(Tree *ptree)
{
	if(PointerIsNull(ptree))
		return;

	DeleteAllNodes(ptree->root);
	InitializeTree(ptree);
}

void PrintNode(Trnode *root)
{
	if(PointerIsNull(root))
		return;

	if(root!= NULL)
	{
		PrintNode(root->left);
		printf("%s %s\n", root->item.patname, root->item.patkind);
		PrintNode(root->right);
	}
}

void PrintTree(Tree *ptree)
{
	if(PointerIsNull(ptree) || ptree->size == 0)
		return;

	PrintNode(ptree->root);
}
