
int multi_before_and_after_negative(int a[20], int size)
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
		
	for(i = size -1 ; i >= 0; --i)
	{
		if(a[i] < 0)
		{
			ln = i;
			break;
		}
	}

	for(i = 0; i < fn; ++i)
		result *= a[i];

	for(i = ln; i < size; ++i)
		result *= a[i];

	return result;
}
