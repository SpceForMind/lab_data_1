
#include <stdio.h>
#include <stdlib.h>

#include "point_2d.h"
#include "point_3d.h"


#define PrintCoordinate(p) _Generic((p),\
	Point_2d * : PrintPoint_2d,\
	Point_3d * : PrintPoint_3d\
	) (p)


int main()
{
	Point_3d *point = NewPoint_3d();
	point->setX((Point_2d *)point, 1);
	point->setY((Point_2d *)point, 2);
	point->z = 3;
	PrintCoordinate((Point_2d *)point);
	PrintCoordinate(point);
	/*
	Point_2d *point = NewPoint_2d();
	point->setX(point, 1);
	point->setY(point, 2.1);
	printf("x = %.3lf, y = %.3lf\n", point->getX(point), point->getY(point));
	DeletePoint_2d(point);
	*/

	return 0;
}
