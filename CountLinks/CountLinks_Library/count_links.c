
#include "count_links_types.h"
#include "count_links.h"


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
