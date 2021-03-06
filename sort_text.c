#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "enter.h"


struct InfoWord
{
	char *word;
	int count;
	struct InfoWord *next;
};

typedef struct InfoWord InfoWord;


void printText(char **text, int nwords)
{
	if(text == NULL)
	{
		printf("No text for print!\n");
		return;
	}
	else
	{
		for(int i = 0; i < nwords; ++i)
			printf("%s ", text[i]);
	}
	
	printf("\n-------------------\n");
}

InfoWord *createBlock(char *word)
{
	InfoWord *tmp = (InfoWord *)malloc(sizeof(InfoWord));
	tmp->word = word;
	tmp->count = 0;
	tmp->next = NULL;

	return tmp;
}


void deleteWords(InfoWord *head)
{
	while(head)
	{	
		InfoWord *time_head = head;

		while(time_head->next)
		{
			if(strncmp(head->word, time_head->next->word, strlen(head->word) + 1) == 0)
			{
				if(time_head->next!= NULL)
				{
					time_head->next = time_head->next->next;
					continue;
				}
				else
				{
					time_head->next = NULL;
					break;
				}
			}

			time_head = time_head->next;

			if(time_head == NULL)
				break;
		}	
			
		head = head->next;
	}
}




void createList(InfoWord **head, char **text, int nwords)
{
	if(*head == NULL)
		*head = createBlock(text[0]);

	InfoWord *time_head = *head;
	
	for(int i = 1; i < nwords; ++i)
	{
		time_head->next = createBlock(text[i]);
		time_head = time_head->next;
	}
}

int countWord(InfoWord *head, char *string)
{
	int count = 0;

	while(head)
	{
		if(strncmp(head->word, string, strlen(string) + 1) == 0)
			++count;

		head = head->next;
	}

	return count;	
}


void countWordInText(InfoWord *head, char **text)
{
	int i = 0;
	InfoWord *time_head = head;

	while(time_head)
	{
		time_head->count = countWord(head, text[i]);
		
		time_head = time_head->next;
		++i;
	}
}


void printInfo(InfoWord *head)
{
	while(head)
	{
		printf("word: [%s] count in text: %d\n", head->word, head->count);

		head = head->next;
	}
}

void printWords(InfoWord *head)
{
	while(head)
	{
		printf("[%s]\n", head->word);
		head = head->next;
	}	
}


int main()
{
	char c;
	int i = 0, j = 0, nwords = 0;
	char **text = enterText(&nwords);	
	
	InfoWord *head = NULL;
	
	createList(&head, text, nwords);
	countWordInText(head, text);
	deleteWords(head);
	printInfo(head);
	return 0;
}
