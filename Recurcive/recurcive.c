
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define EPS 0.000001

double NegativeNumInDeg(double n, int deg);

double NumInDeg(double n, int deg);



void recurc(int n)
{
	printf("level: %d adress %p\n", n, &n);
	
	if(n < 4)
		recurc(n + 1);
	
	printf("LEVEL: %d ADRESS: %p\n", n, &n);
}


unsigned long fact_num(int n)
{
	unsigned long fact;

	if(n > 0)
		fact = (unsigned long)n * fact_num(n - 1);
	else
		fact = 1;
	
	return fact;
}


void print_binary(unsigned long n)
{
	int bit = n % 2;

	if(n >= 2)
		print_binary(n / 2);

	putchar(bit == 1 ? '1' : '0');
}


unsigned int Fibonacci(unsigned int n)
{
	if(n > 2)
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	else
		return 1;
}


int NumInNullDeg(double n, int deg)
{
	if(deg == 0)
	{
		if(fabs(n) <= EPS)
		{
			fprintf(stderr, "0^0 is undefined!\n");
			return 1;
		}
		else
			return 1;
	}
	else
		return 0;
}


double NegativeNumInDeg(double n, int deg)
{	
	if(NumInNullDeg(n, deg))
		return 1;
	else
		return 1 / NumInDeg(n, -deg);
}

double NumInDeg(double n, int deg)
{
	if(deg < 0)
	{
		double res = NegativeNumInDeg(n, deg);
		
		return res;
	}

	if(NumInNullDeg(n, deg))
		return 1;
	
	double res = n;

	if(deg > 0)
		res = res * NumInDeg(n, deg - 1);	
	
	return res;
}



int main()
{
	double num = NumInDeg(-32, 2);
	printf("num = %lf\n", num);

	return 0;
}
