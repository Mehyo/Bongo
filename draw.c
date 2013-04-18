#include <cairo/cairo.h>
#include <cairo/cairo-pdf.h>
#include <stdlib.h>
#include <stdio.h>

#include "point.h"
#include "draw.h"

cairo_t* cr;
cairo_surface_t* pdf_surface;

void draw_line (cairo_t* cr,  Point p1, Point p2){

  //Place le point courant en (10,10)
  cairo_move_to(cr, p1->x , p1->y );
  //Enregistrer la ligne du point (10,10) au point (50,50)
  cairo_line_to(cr, p2->x , p2->y );
  //Met la largeur de trait a 10
  cairo_set_line_width (cr, 10.0);
  //Tracer la ligne
  cairo_stroke(cr);

}

void destroy(){
  //Liberation du contexte
  cairo_destroy(cr);
  //Liberation de la surface
  cairo_surface_destroy(pdf_surface);
}

int draw(Point p1, Point p2){
  
  if(!cr){
    //Creation de la surface pdf associee au fichier ex1.pdf
    pdf_surface = cairo_pdf_surface_create("test.pdf",250, 250);

    //Creation du contexte cairo associe a la surface
    cr = cairo_create(pdf_surface);
  }

  printf("P1 %d, %d \n", p1->x, p1->y);
  printf("P2 %d, %d \n", p2->x, p2->y);

  draw_line(cr, p1, p2);

  return 0;
}

int* length_test(int i, int* tab){
  if(i == 0)
    tab = malloc(4*sizeof(int*));
  else
    if(i%4 == 0)
      tab = realloc(tab, 2*i*sizeof(*tab));
  
  return tab;
}