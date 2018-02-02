
#include <stdio.h>
#include <stdlib.h>
#include "point_2d.h"
#include "point_3d.h"

typedef struct private 
{
	double x;
	double y;
} Private;


int PointerIsNull(void *p)
{
	if(p == NULL)
	{
		printf("NULL pointer!\n");
		return 1;
	}
	else
		return 0;
}


static double getX(Point_2d *point)
{
	if(PointerIsNull(point))
		exit(1);

	return ((Private *)point->private_point_2d)->x;
}

static double getY(Point_2d *point)
{
	if(PointerIsNull(point))
		exit(1);

	return ((Private *)point->private_point_2d)->y;
}

static void setX(Point_2d *point, double new_x)
{
	if(PointerIsNull(point))
		return;

	((Private *)point->private_point_2d)->x = new_x;
}


static void setY(Point_2d *point, double new_y)
{
	if(PointerIsNull(point))
		return;

	((Private *)point->private_point_2d)->y = new_y;
}


Point_2d *NewPoint_2d()
{
	Point_2d *new_point = (Point_2d *)malloc(sizeof(Point_2d));
	
	if(PointerIsNull(new_point))
	{
		fprintf(stderr, "No memory!\n");
		exit(1);
	}
	
	new_point->private_point_2d = malloc(sizeof(Private));
	new_point->getX = getX;
	new_point->setX = setX;
	new_point->getY = getY;
	new_point->setY = setY;

	return new_point;
}

Point_3d *NewPoint_3d()
{
	Point_3d *new_point = (Point_3d *)NewPoint_2d();
	new_point = realloc(new_point, sizeof(Point_3d));
	new_point->z = 0;

	return new_point;
}

void DeletePoint_2d(Point_2d *point)
{
	if(PointerIsNull(point))
		return;
	if(!PointerIsNull(point->private_point_2d))
		free(point->private_point_2d);
}


void PrintPoint_2d(Point_2d *point)
{
	if(PointerIsNull(point))
		return;

	printf("x = %lf\ny = %lf", point->getX(point), point->getY(point));
	printf("\n-----------\n");
}


void PrintPoint_3d(Point_3d *point)
{
	if(PointerIsNull(point))
		return;

	printf("x = %lf\ny = %lf\nz= %lf", point->getX((Point_2d *)point), point->getY((Point_2d *)point), point->z);
	printf("\n------------\n");
}
