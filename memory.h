#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

typedef long Aligin;

struct Header
{
	char free_flag;
	int size;
	void *ptr;
	struct Header *next;
	Aligin x;
};

typedef struct Header Header;

Header *head = NULL;


Header *addBlock(Header **head, unsigned bytes)
{
	if(*head == NULL)
	{
		*head = (Header *)sbrk(sizeof(Header));
		(*head)->size = bytes;
		(*head)->ptr = (void *)sbrk(bytes);
		(*head)->next = NULL;
		(*head)->free_flag = 0;
		return (*head);
	}

	Header *time_head = *head;
	
	while(time_head->next)
		time_head = time_head->next;

	time_head->next = (Header *)sbrk(sizeof(Header));
	time_head->next->ptr = (void *)sbrk(bytes);
	time_head->next->size = bytes;
	time_head->next->free_flag = 0;
	time_head->next->next = NULL;

	return time_head->next;
}


void *malloc(unsigned long bytes)
{
	Header *time_head = head;

	while(time_head)
	{	
		if((time_head->size >= bytes) && (time_head->free_flag == 1))
		{
			time_head->free_flag = 0;
			return (void *)time_head->ptr;
		}

		time_head = time_head->next;
	}

	Header *new_block = addBlock(&head, bytes);
	return new_block->ptr;
}

void free(void *block)
{
	if(block == NULL)
		return;

	Header *time_head = head;

	while(time_head)
	{
		if(block == time_head->ptr)
		{	
			time_head->free_flag = 1;
			return;
		}

		time_head = time_head->next;
	}
	
	printf("Segmentation fault [%p]", block);
	exit(1);
}


