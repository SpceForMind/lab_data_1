#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct MusicalComposition
{
	char name[80];
	char author[80];
	int year;
	struct MusicalComposition *next;
	struct MusicalComposition *pred;
}MusicalComposition;



MusicalComposition *createMusicalComposition(char *name, char *author, int year)
{
	MusicalComposition *tmp = (MusicalComposition *)malloc(sizeof(MusicalComposition));
	strncpy(tmp->name, name, strlen(name) + 1);
	strncpy(tmp->author, author, strlen(author) + 1);
	tmp->year = year;
	tmp->next = NULL;

	return tmp;
}

MusicalComposition *createMusicalCompositionList(char **array_names, char **array_authors, int *array_years, int n)
{
	MusicalComposition *head = (MusicalComposition *)malloc(sizeof(MusicalComposition)), *tmp = head;
	strncpy(head->name, array_names[0], strlen(array_names[0]) + 1);
	strncpy(head->author, array_authors[0], strlen(array_authors[0]) + 1);
	printf("head author = %s\n", head->author);
	head->year = array_years[0];
	head->pred = NULL;

	int i = 1;

	for(; i < n; ++i)
	{
		head->next = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
		head->next->pred = head;
		head = head->next;
	}
	
	return tmp;
}


void removeEl(MusicalComposition *head, char *name_for_remove)
{
	MusicalComposition *tmp;

	while(head->next)
	{
		if(strcmp(head->next->name, name_for_remove) == 0)
		{
			if(head->next->next == NULL)
			{
				head->next = NULL;
				return;
			}
			else
			{
				tmp = head;
				head->next = head->next->next;
				head->pred = tmp;
			}
		}

		head = head->next;
	}
}


void delete_by_sub_El(MusicalComposition **main_head, char *substring)
{
	MusicalComposition *head = *main_head;
	int len = strlen(substring) - 1, i = 0, head_flag = 0;

	while(head)
	{
		int author_len = strlen(head->author) - 1;

		while(i <= author_len - len + 1)
		{
			if(strncmp(head->author + i, substring, len) == 0)
			{
				if(head->pred == NULL)
				{
					(*main_head) = head->next;
					(*main_head)->pred = NULL;
					head = *main_head;
					head_flag = 1;
					i = 0;
					break;
				}
				else if(head->next!= NULL)
				{	
					head->pred->next = head->next;
					head->next->pred = head->pred;
					break;
				}
				else if(head->next == NULL)
				{
					head->pred->next = NULL;
					break;
				}
			}
			++i;
		}

		if(!head_flag)
		{	i = 0;
			head = head->next;
		}

		head_flag = 0;
	}
}


void printList(MusicalComposition *head)
{
	if(head == NULL)
		return;

	while(head)
	{
		if(head)
			printf("%s\n", head->name);
		head = head->next;
	}

	printf("--------------------\n");
}


void free_arr(char **names, char **authors, int *years, int length)
{
	for(int j = 0; j < length; ++j)
	{
		free(names[j]);
		free(authors[j]);
	}	

	free(names);
	free(authors);
	free(years);

}

int main()
{
	int length, i = 0;
	scanf("%d\n", &length);

	char **names = (char **)malloc(sizeof(char *) * length);
	char **authors = (char **)malloc(sizeof(char *) * length);
	int *years = (int *)malloc(sizeof(int) * length);

	for(; i < length; ++i)
	{
		char name[80];
		char author[80];
		
		fgets(name, 80, stdin);
		fgets(author, 80, stdin);
		fscanf(stdin, "%d\n", &years[i]);

		(*strstr(name, "\n")) = 0;
		(*strstr(author, "\n")) = 0;

		names[i] = (char *)malloc(sizeof(char) * (strlen(name) + 1));
		authors[i] = (char *)malloc(sizeof(char) * (strlen(author) + 1));

		strncpy(names[i], name, strlen(name) + 1);
		strncpy(authors[i], author, strlen(author) + 1);
	}

	MusicalComposition *head = createMusicalCompositionList(names, authors, years, length);
	
	free_arr(names, authors, years, length);
	printList(head);
	
	
	char *substring = (char *)malloc(sizeof(char) * 80);

	fgets(substring, 80, stdin);
	printf("substring = %s", substring);

	delete_by_sub_El(&head, substring);
	printList(head);

	return 0;
}
