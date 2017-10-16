#include "multi_between_negative.h"
#include "index_first_negative.h"
#include "index_last_negative.h"

int multi_between_negative(int a[20], int size)
{
	int i, result = 1;
	int fn, ln;
	
	fn = index_first_negative(a, size);
	ln = index_last_negative(a, size);

	for(i = fn; i < ln; ++i)
		result *= a[i];

	return result;
}
