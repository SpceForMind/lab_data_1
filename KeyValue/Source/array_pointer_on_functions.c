
#include <stdio.h>
#include <stdlib.h>


typedef double (*PointerOnFun) (double, int);


typedef struct operations
{
	PointerOnFun pnum_in_deg;
	void (*print)(double);
} Operations;


double NumInDeg(double num, int deg)
{
	double time_num = 1;

	for(int i = 0; i < deg; ++i)
		time_num *= num;

	if(deg >= 0)
		return time_num;
	else 
		return 1 / time_num;
}


static void Print(double num)
{
	printf("%.10lf\n", num);
}



int main()
{
	/*
	PointerOnFun *pfun = (PointerOnFun *)malloc(2 * sizeof(PointerOnFun));
	
	pfun[0] = NumInDeg;

	Print(pfun[0](3.14, 10));	
	*/
	
	Operations operation = {.pnum_in_deg = NumInDeg, .print = Print};

	operation.print(operation.pnum_in_deg(3.14, 2));
	
	


	return 0;
}
