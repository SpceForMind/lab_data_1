#pragma once

typedef struct point_2d
{
	void *private_point_2d;
	
	double (*getX)(struct point_2d *point);
	void (*setX)(struct point_2d *point, double new_x);
	double (*getY)(struct point_2d *point);
	void (*setY)(struct point_2d *point, double new_y);
} Point_2d;


Point_2d *NewPoint_2d();

void DeletePoint_2d(Point_2d *point);

void PrintPoint_2d(Point_2d *point);

