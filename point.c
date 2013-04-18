<<<<<<< HEAD
#include <stdlib.h>
#include "point.h"
=======
#include "point.h"
#include <stdlib.h>
>>>>>>> 3e7b505f56bb1fdcccc2dd0ed969bb11410ab170

Point create_point_nul()
{
<<<<<<< HEAD
	point p = malloc(sizeof(point));
=======
	Point p = malloc(sizeof(*p));
>>>>>>> 3e7b505f56bb1fdcccc2dd0ed969bb11410ab170
	p->x=0;
	p->y=0;
	return p;
}

Point create_point(int x, int y)
{
<<<<<<< HEAD
	point p = malloc(sizeof(point));
=======
	Point p = malloc(sizeof(*p));
>>>>>>> 3e7b505f56bb1fdcccc2dd0ed969bb11410ab170
	p->x = x;
	p->y = y;
	return p;
}

Point set_xy(Point p, int x, int y)
{
	p->x=x;
	p->y=y;
	return p;
}

Point set_x(Point p, int x)
{
	p->x=x;
	return p;
}

Point set_y(Point p, int y)
{	
	p->y=y;
	return p;
}

<<<<<<< HEAD
void destroy_point(point p)
=======
int get_x(Point p)
{
	return p->x;
}
int get_y(Point p)
{
	return p->y;
}

void destroy_point(Point p)
>>>>>>> 3e7b505f56bb1fdcccc2dd0ed969bb11410ab170
{
	free(p);
}