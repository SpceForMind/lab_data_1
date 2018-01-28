#include <string.h>

typedef int Item;

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



void Swap(Item *a, Item *b)
{
	if(PointerIsNull(a) || PointerIsNull(b))
		return;

	Item time_a = *a;
	*a = *b;
	*b = time_a;
}

void QuickSort(Item *arr, int start, int end)
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
	}
	
	if(start < right)
		QuickSort(arr, start, right);
	
	if(end > left)
		QuickSort(arr, left, end);

}


void TurnSort(Item *arr, const unsigned int n, int (*p_cmp)(Item *, Item *))
{
	if(PointerIsNull(arr))
		return;

	int i, j;
	int min_index;

	for(i = 0; i < n; ++i)
	{
		min_index = i;

		for(j = i + 1; j < n; ++j)
			if(p_cmp(&arr[min_index], &arr[j]))
				min_index = j;

		Item time_item = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = time_item;
	}
}


void InsertSort(Item *arr, const unsigned int n, int (*p_cmp)(Item *, Item *))
{
	if(PointerIsNull(arr) || PointerIsNull(p_cmp))
		return;

	int i, j;
	Item *time_item = (Item *)malloc(sizeof(Item));

	for(i = 1; i < n; ++i)
		if(p_cmp(&arr[i - 1], &arr[i]))
		{
			j = i;
			while(p_cmp(&arr[j - 1], &arr[j]) && j > 0)
			{
				memcpy(time_item, &arr[j], sizeof(Item));
				memcpy(&arr[j], &arr[j - 1], sizeof(Item));
				memcpy(&arr[j - 1], time_item, sizeof(Item));
				--j;
			}
		}
}


