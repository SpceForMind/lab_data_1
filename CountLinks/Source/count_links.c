
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "count_links_types.h"
//#include "count_links.h"

typedef struct countlink
{
	char *data;
	int *count;
} CountLink;


int PointerIsNull(const void *p)
{
	if(p == NULL)
	{
		printf("NULL pointer!\n");
		return 1;
	}
	else
		return 0;
}


CountLink *NewCountLink(const char *data)
{
	if(PointerIsNull(data))
		return NULL;

	CountLink *new_count_link = (CountLink *)malloc(sizeof(CountLink));

	if(new_count_link == NULL)
	{
		fprintf(stderr, "No memory!\n");
		exit(1);
	}

	new_count_link->data = (char *)data;
	new_count_link->count = (int *)malloc(sizeof(int));
	*new_count_link->count = 1;

	return new_count_link;
}


CountLink *CopyCountLink(const CountLink *pcount_link)
{	
	if(PointerIsNull(pcount_link))
		return NULL;

	CountLink *copy_count_link = (CountLink *)malloc(sizeof(CountLink));
	
	if(copy_count_link == NULL)
	{
		fprintf(stderr, "No memory!\n");
		exit(1);
	}

	*copy_count_link = *pcount_link;
	++*copy_count_link->count;

	return copy_count_link;
}


void FreeCountLink(CountLink *pcount_link)
{
	if(PointerIsNull(pcount_link))
		return ;
	
	*pcount_link->count -= 1;

	if(*pcount_link->count == 0)
	{
		free(pcount_link->data);
		free(pcount_link->count);
	}

	free(pcount_link);
}


void PrintCountLink(CountLink *pcount_link)
{
	if(PointerIsNull(pcount_link))
		return;

	printf("%s\ncount = %d", pcount_link->data, *pcount_link->count);
	printf("\n---------\n");
}


int main()
{
	char *data = (char *)malloc(sizeof(char) * 80);
	fgets(data, 80, stdin);
	(*strstr(data, "\n")) = 0;

	CountLink *count_link = NewCountLink(data);	
	CountLink *copy_count_link = CopyCountLink(count_link);
	
	PrintCountLink(copy_count_link);
	FreeCountLink(copy_count_link);
	copy_count_link = NULL;
	PrintCountLink(count_link);
	copy_count_link = NULL;
	FreeCountLink(count_link);

	return 0;
}
