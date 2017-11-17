#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//#define MAX_SIZE 5000
//#define MAX_SENTENCE 3000


int issym(char c)
{
	if((c >= 65 && c <= 90) || (c >= 97 && c <=122))
		return 1;
	
	return 0;
}

int space(char c)
{
	if(c == ' ' || c == '\t' || c == '\n' || c == ';' || c == '.' || c == '?')
		return 1;
	
	return 0;
}

int isword(char *word)
{
	int c, flag = 0;

	if(issym(*(word - 1)))
		flag = 1;

	while((c = *word++)!= ' ' && c!= ';' && c!= '.' && c!= '?' &&  c!= '\n') 
		if(!isdigit(c))
		{
			if(flag)
				return 0;

			while((c = *word++)!= ' ' && c!= ';' && c!= '.' && c!= '?' && c!= '\n')
				if(isdigit(c))
					return 0;
			return 1;
		}
	return 1;
}



void strn_cat(char *text, char *string, int n)
{
	while(--n > 0)
		*text++ = *string++;
}

void format(char *text, int MAX_SIZE, int MAX_SENTENCE)
{
	char **sentence = (char **)malloc(MAX_SENTENCE * sizeof(char *));
	char sym;
	int i = 0, j = 0, k, n = 0, free_i, nsent; 
	
	sentence[0] = &text[0];
	nsent = 1;

	while((sym = text[i])!= '\0')
	{
		if(sym == ';' || sym == '.' || sym == '?')
		{
			++j;
			sentence[j] = &text[++i];
			++nsent;
			continue;
		}
		++i;	
	}

	free_i = i;
	j = 0;
	i = 0;


	while(*(sentence[j] + i))
	{

		
		if(*(sentence[j] + i) == '.' || *(sentence[j] +i) == ';' || *(sentence[j] + i) == '?')
		{
			++j;
			i = 0;
		}

		if(isdigit(*(sentence[j] + i)))
		{
			if(j == 0 && !space(*(sentence[j] +i +1)) && !isword((sentence[j] + i)))
			{
				
				sentence[j++] = NULL;
				i = 0;
				continue;
			}

			if(!space(*(sentence[j] + i + 1)) && !space(*(sentence[j] + i -1)) && !isword(sentence[j] + i))
			{
				sentence[j++] = NULL;
				i = 0;
				continue;
			}
		}
				++i;
	}
	i = 0;
	j = 0;

	int m = 0;

	
	
	char *ftext = (char *)malloc(MAX_SIZE), *tmp = ftext;
	char **tmpsentence = (char **)malloc(MAX_SENTENCE);
	int g = 0;

//	*ftext++ = '\n';

	for(int b = 0; b <= nsent; ++b)
	{
		if(sentence[b]!= NULL)
		{
			tmpsentence[g++] = sentence[b];
		}
	}


	int start = 1;

	while(*(tmpsentence[j] + i))
	{	
		
/*
		if((start) && (*(tmpsentence[j] + i) == '\t'))
		{
			printf("yes!\n");
			++i;
			start = 0;
		}
*/
		if(*(tmpsentence[j] + i) == '.' || *(tmpsentence[j] + i) == '?' || *(tmpsentence[j] + i) == ';')
		{
			*ftext++ = *(tmpsentence[j] + i);
			*ftext++ = '\n';
			++j;
			i = 0;	
			start = 1;
		}
		if((*(tmpsentence[j] + i) == '\t' || *(tmpsentence[j] + i) == ' ') && start)
		{
			start = 0;
			++i;
			continue;
		}

		*ftext++ = *(tmpsentence[j] + i);
		++i;
	}

	sprintf(ftext, "\nКоличество предложений до %d и количество предложений после %d", nsent - 1, g - 1);
	printf("%s", tmp);

//	free(tmpsentence);
	//free(tmp);
	free(sentence);	


}
	


typedef struct Text
{
	char data[100];
	struct Text *next;
}Text;




void add_item(Text *sentence)
{
	Text *tmp = (Text *)malloc(sizeof(Text));
	sentence->next = tmp;
}


int main()
{
	Text *first = (Text *)malloc(sizeof(Text));
	Text *ftmp = first, *ftemp = first ;
	
	int i = 0, j = 1, point = 0, k = 0;
	char c;

	while((c = getchar())!= '\n')
	{
		if(c == '.' || c == '?' || c == ';')
			++point;

		if(i < 100)
		{
			(first->data[i]) = c;
			++i;
		}
		else
		{
			first->data[i] = '\0';
			++j;
			i = 0;
			add_item(first);
			first = first->next;
		}
	}
	first->data[i] = '\0';
	if(!point)
		return 0;

	printf("sentence = %d\n", point);


	j += 2;
	i = 0;

	
	char *text = (char *)malloc(100 * j);
	int MAX_SIZE = 100 * j, MAX_SENTENCE = point, sword;


	while(ftmp) 
	{
		if(i < 99)
		{
			text[k++] = ftmp->data[i++];
		}
		else
		{
			i = 0;
			ftmp = ftmp->next;
		}
	}
	text[k] = '\0';

	printf("%s\n", text);
//	format(text, MAX_SIZE, MAX_SENTENCE);

	free(ftemp);
	free(text);

	return 0;
}
