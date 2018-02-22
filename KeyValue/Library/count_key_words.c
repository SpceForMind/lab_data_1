
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "constant.h"
#include "API.h"


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
