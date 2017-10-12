
int multi_before_and_after_negative(int a[20], int size, int fn, int ln)
{
int  i, result = 1;


	for(i = 0; i < fn; ++i)
		result *= a[i];

	for(i = ln; i < size; ++i)
		result *= a[i];

	return result;
}
