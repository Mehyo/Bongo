#ifndef POINT_H
#define POINT_H

struct point
{
  int x;
  int y;
};
<<<<<<< HEAD
typedef struct point * point;
=======
>>>>>>> 3e7b505f56bb1fdcccc2dd0ed969bb11410ab170

typedef struct point * Point;

Point create_point_nul();
Point create_point(int x, int y);

<<<<<<< HEAD
void destroy_point(point p);
=======
Point set_xy(Point p , int x, int y);
Point set_x(Point p , int x);
Point set_y(Point p , int y);

int get_x(Point p);
int get_y(Point p);

void destroy_point(Point p);
>>>>>>> 3e7b505f56bb1fdcccc2dd0ed969bb11410ab170


#endif