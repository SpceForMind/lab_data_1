
#include <stdio.h>

#include "index_first_negative.h"
#include "index_last_negative.h"
#include "multi_between_negative.h"
#include "multi_before_and_after_negative.h"


int main()
{
	int size = 0;
	int a[21];
	unsigned i;

	for(i = 0; i < 21; ++i)
	{
		size += scanf("%d ", &a[i]);	
	}

	size -= 1;
	printf("size = %d\n", size);
	switch(a[0])
	{
		case 0:
			printf("%d\n", index_first_negative((a+1), size));			
			break;

		case 1:
  			printf("%d\n", index_last_negative((a+1), size));
			break;

		case 2:
			printf("%d\n", multi_between_negative((a+1),size));
			break;

		case 3:
			printf("%d\n", multi_before_and_after_negative((a+1), size));	
			break;

		default:
			printf("Данные некоректны");
	}	

	return 0;
}
