
#include <stdio.h>


typedef struct point_2d
{
	double x;
	double y;
} Point_2d;


typedef struct point_3d
{
	union
	{
		struct point_2d;
		Point_2d point_xy;
	};
	double z;
} Point_3d;


void PrintPoint_2d(Point_2d point)
{
	printf("x = %lf y = %lf\n", point.x, point.y);
}


void PrintPoint_3d(Point_3d point)
{
	printf("x = %lf y = %lf z = %lf\n", point.x, point.y, point.z);
}


#define u_print(X) _Generic((X),\
	Point_2d : PrintPoint_2d,\
	Point_3d : PrintPoint_3d) (X)


int main()
{
	Point_2d point = {.x = 1, .y = 2};

	u_print(point);


	return 0;
}


