#ifndef POINT_H
#define POINT_H

struct point
{
  int x;
  int y;
};
typedef struct point * point;

point create_point_nul();
point create_point(int x, int y);

point set_xy(point p , int x, int y);
point set_x(point p , int x);
point set_y(point p , int y);

void destroy_point(point p);


#endif