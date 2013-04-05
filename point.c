#include point.h

point create_point_nul()
{
	point p = malloc(sizeof(p*));
	p->x=0;
	p->y=0;
	return p;
}

point create_point(int x, int y)
{
	point p = malloc(sizeof(p*));
	p->x = x;
	p->y = y;
	return p
}

point set_xy(point p, int x, int y)
{
	p->x=x;
	p->y=y;
	return p;
}

point set_x(point p, int x)
{
	p->x=x;
	return p;
}

point set_y(point p, int y)
{	
	p->y=y;
	return p;
}

point get_x(point p, int x)
{
	return p->x;
}
point get_y(point p, int y)
{
	return p->y;
}

void destroy_point(point p)
{
	free(p)
}