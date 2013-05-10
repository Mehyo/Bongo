#include "point.h"
#include <stdlib.h>
#include <stdio.h>

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

void destroy_point(Point p)
{
	free(p);
}

void toString(Point p){
	printf("X = %d\n Y = %d\n",p->x, p->y);
}