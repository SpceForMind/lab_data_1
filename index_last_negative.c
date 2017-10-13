#include "index_last_negative.h"

int index_last_negative(int a[20], int size)
{
	int i;

	for(i = size - 1; i >= 0; --i)
	{
		if(a[i] < 0)
			return i;
	}
}

