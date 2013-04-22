#ifndef DRAW_H
#define DRAW_H

#include "point.h"

int* pos_tab;
int tab_length;

void destroy();

void draw();
void fill();

int* length_test(int i, int* tab);

void calc(Stack stack_number, Stack stack_operator);
void cycle();
void translate();
void polaire();

#endif