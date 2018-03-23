
#include <stdio.h>



int CountNumeral(long int num)
{
	int count = 1;

	while(num / 10!= 0)
	{
		++count;
		num /= 10;
	}

	return count;
}



int main()
{
	long int num;

	if(scanf("%ld", &num)!= 1)
		return 0;

	printf("%d", CountNumeral(num));

	return 0;
}
