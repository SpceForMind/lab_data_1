#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define WORD_SIZE 50


struct InfoWord
{
	char word[WORD_SIZE];
	int string_num;
	struct InfoWord *next;
};


typedef struct InfoWord InfoWord;



int endSentence(char c)
{
	if(c == '.' || c == ';' || c == '?')
		return 1;
	else
		return 0;
}


void printText(char **text, int nwords)
{
	for(int i = 0; i < nwords; ++i)
		printf("%s ", text[i]);

	printf("\n-----------------\n");
}


InfoWord *addBlock(char *word, int string_num)
{
	InfoWord *tmp = (InfoWord *)malloc(sizeof(InfoWord));
	strncpy(&tmp->word[0], word, strlen(word) + 1);
	tmp->string_num = string_num;
	tmp->next = NULL;

	return tmp;
}


void createList(InfoWord **head)
{
	char c;
	int i = 0, string_num = 1;

	InfoWord *time_head = *head;

	while((c = getchar())!= '!')
	{
		if(c == '\n')
			++string_num;

		char word[WORD_SIZE];

		while(!isspace(c) && !endSentence(c) && c!= '!' && (i < 50))
		{	
			word[i] = c;
			c = getchar();
			++i;
		}
		
		if(c == '!')
		{
			word[i] = '\0';
			time_head->next = addBlock(word, string_num);
			return;
		}

		word[i] = '\0';
		i = 0;

		if(*head == NULL)
		{
			*head = addBlock(word, string_num);
			time_head = *head;
			continue;
		}
	
		time_head->next = addBlock(word, string_num);
		time_head = time_head->next;	
	}
}
 
void printWords(InfoWord *head)
{
	while(head)
	{
		printf("%d: %s\n", head->string_num, head->word);

		head = head->next;
	}
}

int main()
{
	InfoWord *head = NULL;
	createList(&head);		
	printWords(head);

	return 0;
}
