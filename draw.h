#ifndef DRAW_H
#define DRAW_H

#include "point.h"

void destroy();
int draw(Point p1, Point p2);
void fill(Point* tab_point, int length);
int* length_test(int i, int* tab);

#endif