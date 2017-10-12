
int multi_between_negative(int a[20], int size, int fn, int ln)
{
	int i, result = 1;

	for(i = fn; i < ln; ++i)
		result *= a[i];

	return result;
}
