
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>





struct Text 
{
	struct Text *next;
	char data[200];
};

typedef struct Text Text;


void add_text(Text *text)
{
	Text *tmp = (Text *)malloc(sizeof(Text));
	text->next = tmp;
	text->next->next = NULL;
}



void format_sentence(char *string, int *aftersentence)
{
	int dig_flag = 0, sym_flag = 0, i = 0;
	char *tmp = string;

	while(*string)
	{
		if(!isdigit(*string) && !isspace(*string))	
		{
			*string++;

			while(*string!= '.' && *string!= ' ' && *string!= ';' && *string!= '?')
			{
				if(isdigit(*string))
					dig_flag = 1;

				if(dig_flag == 1 && !isdigit(*string))
				{
					*aftersentence -= 1;
					*tmp = '\0';
					return;
				}

				*string++;
			}
			dig_flag = 0;
		}

		if(isdigit(*string) && !isspace(*string))
		{
			*string++;

			while(*string!= ' ' && *string!= '.' && *string!= ';' && *string!= '?')
			{
				if(!isdigit(*string))
					sym_flag = 1;

				if(sym_flag == 1 && isdigit(*string))
				{
					*aftersentence -= 1;
					*tmp = '\0';
					return;
				}
				
				*string++;
			}
			sym_flag = 0;
		}

		*string++;
	}


/*
	while(sentence->data[i]!= '\0')
	{
		if(!isdigit(sentence->data[i]))
		{
			++i;

			while(sentence->data[i]!= ' ' &&  sentence->data[i]!= '.' &&  sentence->data[i]!= ';' && sentence->data[i]!= '?')
			{
				if(isdigit(sentence->data[i]))
					dig_flag = 1;

				if(dig_flag == 1 && !isdigit(sentence->data[i]))
				{
					sentence = NULL;
					return;
				}
				

				++i;
			}
			dig_flag = 0;

		}

		if(isdigit(sentence->data[i]))
		{
			++i;
			
			while(sentence->data[i]!= ' ' && sentence->data[i]!= '.' && sentence->data[i]!= '?' && sentence->data[i]!= ';')
			{
				if(!isdigit(sentence->data[i]))
					sym_flag = 1;

				if(isdigit(sentence->data[i]) && sym_flag == 1)
				{
					sentence = NULL;
					return;
				}
				
				++i;
			}
			sym_flag = 0;
		}

		++i;
	}*/
}


void format(Text *text, int nsentence, int *aftersentence)
{
	Text *tmp;
	int i = 0;

	while(--nsentence >= 0)
	{
		tmp = text->next;
		format_sentence(text->data, aftersentence);	
		text = tmp;
	}
}




int main()
{
	Text *text = (Text *)malloc(sizeof(Text)), *tmp = text, *ptmp = text;
	char c;
	int i = 0, nsentence = 0, flag = 0, aftersentence = 0;

	while((c = getchar())!= '!')
	{
		if(flag == 0 && (c == ' ' || c == '\t'))
		{	
			flag = 1;
			continue;
		}

		if(c!= '.' && c!= ';' && c!= '?')
		{
			text->data[i] = c;
			++i;
		}
		else
		{
			++nsentence;
			text->data[i++] = c;
			text->data[i++] = '\n';
			text->data[i] = '\0';
			add_text(text);
			text = text->next;
			i = 0;
			flag = 0;
		}
	}

	if(nsentence == 0)
		return 0;

	text->data[i++] = '!';
	text->data[i++] = '\n';
	text->data[i] = '\0';
	aftersentence = nsentence;

	format(tmp, nsentence, &aftersentence);
	sprintf(&(text->data[i]), "Количество предложений до %d и количество предложений после %d", nsentence, aftersentence);

	while(tmp)
	{
		if(tmp->data[0]!= '\0')
			printf("%s", tmp->data);

		tmp = tmp->next;
	}

	//printf("sentence = %d\n", nsentence);
/*
	while(tmp)
	{
		printf("%s", tmp->data);
		tmp = tmp->next;
	}
*/
	

	return 0;
}
