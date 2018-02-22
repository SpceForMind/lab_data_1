#include "types.h"

int PointerIsNull(const void *p);

int IsEmpty(Stack *pstack);

Node *MakeNode(Type data);

void Push(Stack *pstack, Node *new_node);

Type Pop(Stack *pstack);

Type Top(Stack *pstack);

void PrintStack(Stack *pstack);

void Initialize(Stack *pstack);

