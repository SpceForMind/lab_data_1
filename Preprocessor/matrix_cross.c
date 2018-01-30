
#include <stdio.h>
#include <math.h>


void matrix_cross_base(double *list1, double *list2)
{
	int count1 = 0, count2 = 0;

	while(!isnan(list1[count1])) 
		++count1;
	while(!isnan(list2[count2]))
		++count2;
	
	if(count1 == 0 || count2 == 0)
	{
		printf("No data!\n");
		return;
	}

	for(int i = 0; i < count1; ++i)
	{
		for(int j = 0; j < count2; ++j)
			printf("%lf\t", list1[i] * list2[j]);

		printf("\n");
	}
}


#define make_a_list(...) (double[]){__VA_ARGS__, NAN}

#define matrix_cross(list1, list2) (matrix_cross_base(make_a_list list1, make_a_list list2))


int main()
{
//	matrix_cross((1, 2, 3, 4, 5), (1, 2, 3, 4, 5));
	matrix_cross((1, 2, 3), (4, 5, 6));

	return 0;
}
