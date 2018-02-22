
#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "API.h"


int main()
{
	Stack stack;

	Initialize(&stack);

	for(int i = 0; i < 5; ++i)
	{
		Node *new_node = MakeNode(i);
		stack.push(&stack, new_node);
	}
	
	stack.print(&stack);
	printf("top : %d\n", stack.top(&stack));

	while(!stack.is_empty(&stack))
		printf(">>%d\n", stack.pop(&stack));


	return 0;
}
