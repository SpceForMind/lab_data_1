
#include "point_2d.h"

typedef struct point_3d
{
	union 
	{
		struct point_2d;
		Point_2d point_xy;
	};
	double z;
} Point_3d;


Point_3d *NewPoint_3d();

void PrintPoint_3d(Point_3d *point);

