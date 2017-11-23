#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct text
{
	char sentence[250];
	struct text *next;
};

typedef struct text Text;



void add_text(Text *text)
{
	Text *tmp = (Text *)malloc(sizeof(Text));
	tmp->next = NULL;
	text->next = tmp;
}

int end_sentence(char c)
{
	if(c == '.' || c == ';' || c == '?')
		return 1;
	else
		return 0;
}


void print_text(Text *head)
{
	while(head)
	{
		printf("%s", head->sentence);
		head = head->next;
	}
}






int main()
{
	int i = 0;
	char c;
	Text *text = (Text *)malloc(sizeof(Text));
	Text *tmp = text;

	while((c = getchar())!= '!')
	{
		if(end_sentence(c))
			text->sentence[i++] = c;
		else
		{
			text->sentence[i++] = c;
		//	text->sentence[i++] = '\n';
			text->sentence[i] = '\0';
			add_text(text);
			text = text->next;
			i = 0;
		}
	}

	text->sentence[i++] = '!';
	text->sentence[i++] = '\n';
	text->sentence[i] = '\0';

	print_text(tmp);

	return 0;
}




