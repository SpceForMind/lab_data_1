
int index_first_negative(int a[20],int size);
int index_last_negative(int a[20],int size);

int multi_between_negative(int a[20], int size)
{
	int fn, ln, i, result = 1;


	fn = index_first_negative(a, size);
	ln = index_last_negative(a, size);


	for(i = fn; i < ln; ++i)
		result *= a[i];

	return result;
}
