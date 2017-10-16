#include "multi_before_and_after_negative.h"
#include "index_first_negative.h"
#include "index_last_negative.h"

int multi_before_and_after_negative(int a[20], int size)
{
	int  i, result = 1;
	int fn, ln;

 	fn = index_first_negative(a, size);
	ln = index_last_negative(a, size);

	for(i = 0; i < fn; ++i)
		result *= a[i];

	for(i = ln; i < size; ++i)
		result *= a[i];

	return result;
}
