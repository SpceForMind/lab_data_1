#include <stdio.h>
#include <stdlib.h>


typedef int Type;


int PointerIsNull(void *p)
{
	if(p == NULL)
	{
		printf("NULL pointer!\n");
		return 1;
	}
	else
		return 0;
}


void PrintArr(Type *arr, const unsigned int n)
{
	if(PointerIsNull(arr))
		return;

	for(int i = 0; i < n; ++i)
		printf("%d ", arr[i]);

	printf("\n-----------\n");
}


void Swap(Type *a, Type *b)
{
	if(PointerIsNull(a) || PointerIsNull(b))
		return;

	Type time_a = *a;
	*a = *b;
	*b = time_a;
}


void QuickSort(Type *arr, int start, int end)
{
	if(PointerIsNull(arr))
		return;

	int left = start;
	int right = end;
	int pmid = arr[(left + right) / 2];

	while(left <= right)
	{
		while(arr[left] < pmid)
			left++;

		while(arr[right] > pmid)
			right--;
		
		if(left <= right)
		{
			Swap(&arr[left], &arr[right]);
			++left;
			--right;	
		}

		PrintArr(arr, 4);
	}
	
	if(start < right)
		QuickSort(arr, start, right);
	
	if(end > left)
		QuickSort(arr, left, end);

}




int main()
{
	Type arr[] = {5, 1, 3, 2};
	QuickSort(arr, 0, 3);
//	PrintArr(arr, 4);	


	return 0;
}
