
#include <stdio.h>

#include "index_first_negative.h"
#include "index_last_negative.h"
#include "multi_between_negative.h"
#include "multi_before_and_after_negative.h"


int main()
{
	int size = 0;
	int a[21];


	size += scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7], &a[8], &a[9], &a[10], &a[11], &a[12], &a[13], &a[14], &a[15], &a[16], &a[17], &a[18], &a[19], &a[20]);

	size -= 1;
	
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
