
#include <stdio.h>

#include "index_first_negative.h"
#include "index_last_negative.h"
#include "multi_between_negative.h"
#include "multi_before_and_after_negative.h"


int main()
{
	int i, size = 0;
	int a[21];


	for(i = 0; i < 20; ++i)
	{
		size += scanf("%d", &a[i]);
	}
	
	size -= 1;
	printf("sizeof(a) = %d\n", size);
	

	switch(a[0])
	{
		case 0:
			printf("index first negative: %d\n", index_first_negative((a+1), size));			
			break;

		case 1:
  			printf("index last negative: %d\n", index_last_negative((a+1), size));
			break;

		case 2:
			printf("multy between negatives first and last: %d\n", multi_between_negative((a+1),size));
			break;

		case 3:
			printf("multy before negatives first and last: %d\n", multi_before_and_after_negative((a+1), size));	
			break;

		default:
			printf("Данные некоректны");
	}	

	return 0;
}
