
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 5000
#define MAX_SENTENCE 3000


int space(char c)
{
	if(c == ' ' || c == '\t' || c == '\n' || c == ';' || c == '.' || c == '?')
		return 1;
	
	return 0;
}


void strn_cat(char *text, char *string, int n)
{
	while(--n > 0)
		*text++ = *string++;
}

void format(char *text)
{
	char **sentence = (char **)malloc(MAX_SENTENCE * sizeof(char *));
	char sym;
	int i = 0, j = 0, k, n = 0,  nsent; 
	
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
			if(j == 0 && !space(*(sentence[j] +i +1)))
			{
				sentence[j++] = NULL;
				i = 0;
				continue;
			}

			if(!space(*(sentence[j] + i + 1)) || !space(*(sentence[j] + i -1)))
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
		if(*(tmpsentence[j] + i) == '\t' && start)
		{
			start = 0;
			++i;
		}

		*ftext++ = *(tmpsentence[j] + i);
		++i;
	}

/*
	FILE *F1;
	F1 = fopen("str.txt", "w");
	fprintf(F1, "Количество строк до %d после %d", nsent - 1, g - 1);
	fclose(F1);
	F1 = fopen("str.txt", "r");
	int c;
	
	while((c = getc(F1))!= EOF)
		*ftext++ = c;	
*/	
	sprintf(ftext, "Количество предложений до %d и количество предложений после %d", nsent - 1, g - 1);
	printf("%s", tmp);
}
	






int main()
{
	
	int max = 0;
	char *text = (char *)malloc(MAX_SIZE);

	fgets(text, MAX_SIZE, stdin);
	format(text);

	free(text);
	return 0;
}
