
#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

void PrintArr(Item *arr, const unsigned int n)
{
	if(PointerIsNull(arr))
		return;

	for(int i = 0; i < n; ++i)
		printf("%d ", arr[i]);

	printf("\n-----------\n");
}

int Compare(Item *a, Item *b)
{
	if(PointerIsNull(a) || PointerIsNull(b))
	{
		fprintf(stderr, "Put NULL pointer!\n");
		exit(1);
	}
	
	return (*a > *b);
}



int main()
{
	Item arr[] = {1, 2, 4, 3, 5, 6};
	
	PrintArr(arr, 6);
	InsertSort(arr, 6, Compare);
	PrintArr(arr, 6);

	return 0;
}
