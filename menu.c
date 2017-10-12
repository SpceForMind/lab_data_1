
#include <stdio.h>
#include <stdlib.h>


int index_first_negative(int a[20], int size);
int index_last_negative(int a[20], int size);
int multi_between_negative(int a[20], int size);
int multi_before_and_after_negative(int a[20], int size);

int main()
{
	int i, size = 0, check = 0;
	int a[20];

      	int value;

        printf("Enter value: ");
	scanf("%d", &value);
        printf("value = %d\n", value);
					

	for(i = 0; i < 20; ++i)
	{
		size += scanf("%d", &a[i]);
	}
	
	printf("sizeof(a) = %d\n", size);


	switch(value)
	{
		case 0:
			printf("index first negative: %d\n", index_first_negative( a, size));			
			break;

		case 1:
  			printf("index last negative: %d\n", index_last_negative(a, size));
			break;

		case 2:
			printf("multy between negatives first and last: %d\n", multi_between_negative(a,size));
			break;

		case 3:
			printf("multy before negatives first and last: %d\n", multi_before_and_after_negative(a, size));	
			break;

		default:
			printf("Данные некоректны");
	}	

	return 0;
}
