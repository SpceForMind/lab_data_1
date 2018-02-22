#include "types.h"

int PointerIsNull(const void *p);
		
void PrintKeyValue(KeyValue *pkeyval);

Node *MakeNode(char *key_word);

void AddNode(KeyValue *pkeyval, Node *new_node);

void Initialize(KeyValue *pkeyval);
