#ifndef DRAW_H
#define DRAW_H

#include "point.h"

int* pos_tab;
int tab_length;

void destroy();

void draw();
void fill();

int* length_test(int i, int* tab);

#endif