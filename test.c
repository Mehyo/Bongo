#include <cairo/cairo.h>
#include <cairo/cairo-pdf.h>
#include <stdlib.h>

#include "test.h"
#include "point.h"

void draw_line (cairo_t* cr,  Point p1, Point p2){

  //Place le point courant en (10,10)
  cairo_move_to(cr, p1->x , p1->y );
  //Enregistrer la ligne du point (10,10) au point (50,50)
  cairo_line_to(cr, p2->x , p2->y );
  //Met la largeur de trait a 10
  cairo_set_line_width (cr, 30.0);
  //Tracer la ligne
  cairo_stroke(cr);

}


int draw(int num1, int num2, int num3, int num4){
  cairo_surface_t *surface;
  cairo_t *cr;
  
  //Creation de la surface pdf associee au fichier ex1.pdf
  cairo_surface_t* pdf_surface = 
    cairo_pdf_surface_create("test.pdf",250, 250);

  //Creation du contexte cairo associe a la surface
  cr=cairo_create(pdf_surface);
  
  Point p1 = create_point(num1, num2);
  Point p2 = create_point(num3, num4);

  draw_line(cr, p1, p2);

  //Liberation du contexte
  cairo_destroy(cr);
  //Liberation de la surface
  cairo_surface_destroy(pdf_surface);
  return 0;
}