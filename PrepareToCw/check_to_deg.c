
#include <stdio.h>



int CheckToDeg(long num)
{
	if(num < 0)
		num = -num;

	long mask = 1;
	int deg_flag = 0;

	for(int i = 0; i < sizeof(num) * 8; ++i)
	{
		if((num & mask) == mask)
			++deg_flag;

		num >>= 1;
	}
	
	if(deg_flag == 1)
		return 1;
	else
		return 0;

}


int main()
{
	long num;
	
	if(scanf("%ld", &num)!= 1)
		return 0;

	if(CheckToDeg(num))
		printf("True");
	else
		printf("False");



	return 0;
}
