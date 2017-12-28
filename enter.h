#include <stdlib.h>

#define COUNT_WORD 100
#define WORD_SIZE 50

int end_sentence(char c)
{
	if(c == '.' || c == ';' || c == '?')
		return 1;
	else
		return 0;
}


char **enterText(int *nwords)
{
	char **text = (char **)malloc(sizeof(char *) * COUNT_WORD);
	int i = 0, j = 0;
	char c;

	while((c = getchar())!= '!')
	{
		if(i % 100 == 0 && i!= 0)
			text = (char **)realloc(text, sizeof(char *) * COUNT_WORD * (i / 100 + 1));

		text[i] = (char *)malloc(sizeof(char) * WORD_SIZE);
		
		while(!isspace(c) && !end_sentence(c) && c!= '!')
		{
			text[i][j] = c;
			c = getchar();
			++j;
		}

		if(c == '!')
		{
			text[i][j] = '\0';
			*nwords += 1;
			break;
		}

		text[i][j] = '\0';
		j = 0;
		++i;
		*nwords += 1;
	}

	return text;
}
