
#include <stdio.h>
#include <math.h>


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
		Point_2d point_on_xy;
	};
	double z;
} Point_3d;


static double LengthToPlane(const Point_2d point)
{
	return sqrt(point.x * point.x + point.y * point.y);
}


static double LengthToPoint(const Point_3d point)
{
	return sqrt(point.x * point.x + point.y * point.y + point.z + point.z);
}


int main()
{
	Point_3d point = {.x = 5, .y = 0, .z = 0};
	
	printf("%lf\n%lf\n", LengthToPlane(point.point_on_xy), LengthToPoint(point));


	return 0;
}
