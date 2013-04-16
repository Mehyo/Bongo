#include "point.h"
#include <stdlib.h>

Point create_point_nul()
{
	Point p = malloc(sizeof(*p));
	p->x=0;
	p->y=0;
	return p;
}

Point create_point(int x, int y)
{
	Point p = malloc(sizeof(*p));
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

int get_x(Point p)
{
	return p->x;
}
int get_y(Point p)
{
	return p->y;
}

void destroy_point(Point p)
{
	free(p);
}