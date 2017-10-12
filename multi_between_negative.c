
int multi_between_negative(int a[20], int size)
{
	int fn, ln, i, result = 1;

	for(i = 0; i < size; ++i)
	{
		if(a[i] < 0)
		{
			fn = i;
			break;
		}
	}

	for(i = size - 1; i >= 0; --i)
	{
		if(a[i] < 0)
		{
			ln = i;
			break;
		}
	}

	for(i = fn; i < ln; ++i)
		result *= a[i];

	return result;
}
