#ifndef POINT_H
#define POINT_H

struct point
{
  int x;
  int y;
};

typedef struct point * Point;

Point create_point_nul();
Point create_point(int x, int y);

Point set_xy(Point p , int x, int y);
Point set_x(Point p , int x);
Point set_y(Point p , int y);

int get_x(Point p);
int get_y(Point p);

void destroy_point(Point p);


#endif