
#include <stdio.h>
#include <math.h>






int main()
{
	double num;
	
	if(scanf("%lf", &num)!= 1)
		return 0;
	
	double franction;
	double real;
	franction = modf(num, &real);

	printf("%.1lf\n%lf", real, franction);



	return 0;
}
