#ifndef DRAW_H
#define DRAW_H

#include "point.h"

int** draw_tab;
int* pos_tab;
int tab_length;

void destroy();

void draw();
void fill();

int* length_test(int i, int* tab);

void calc(int i);
void cycle(int i);
void translate(int i);
void polaire(int i);
void restart();
int* term(int length, int* tab);

#endif