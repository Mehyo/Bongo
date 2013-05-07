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

void destroy_point(Point p);

void toString(Point p);

#endif