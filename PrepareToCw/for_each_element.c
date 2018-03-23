
#include <stdio.h>
#include <stdlib.h>


#define ARRSIZE 20

typedef int (*PointerOnFunction)(int );


int ModOnTen(const int num)
{
	return num % 10;
}

int NumInSecondDeg(const int num)
{
	return num * num;
}

int AbcNum(const int num)
{
	if(num < 0)
		return -num;
	else
		return num;
}


void ForEachElement(int *parray, int (*pfun)(int ), int n)
{
	for(int i = 0; i < n; ++i)
		parray[i] = pfun(parray[i]);
}


void PrintArr(const int *parray, int n)
{
	if(parray == NULL)
		return;

	for(int i = 0; i < n - 1; ++i)
		printf("%d ", parray[i]);
	printf("%d", parray[n - 1]);
}


int main()
{
	int array[ARRSIZE];
	int index_fun;
	int size = 0;

	for(int i = 0; i < ARRSIZE; ++i)
	{
		if(scanf("%d ", &array[i])!= 1)
			break;
		++size;
	}

	if(scanf("%d", &index_fun)!= 1)
	{
		printf("Error");
		return 0;
	}

	if(index_fun < 1 || index_fun > 3)
	{
		printf("Error");
		return 0;
	}

	PointerOnFunction *arr_fun = (PointerOnFunction *)malloc(3 * sizeof(PointerOnFunction));
	arr_fun[0] = ModOnTen;
	arr_fun[1] = NumInSecondDeg;
	arr_fun[2] = AbcNum;

	ForEachElement(array, arr_fun[index_fun - 1], size);
	PrintArr(array, size);


	return 0;
}
