#include <cairo/cairo.h>
#include <cairo/cairo-pdf.h>
#include <stdlib.h>
#include <stdio.h>

#include "point.h"
#include "stack.h"
#include "draw.h"

cairo_t* cr;
cairo_surface_t* pdf_surface;

void draw_line (cairo_t* cr,  Point p1, Point p2){

  //Place le point courant en (10,10)
  cairo_move_to(cr, p1->x , p1->y );
  //Enregistrer la ligne du point (10,10) au point (50,50)
  cairo_line_to(cr, p2->x , p2->y );
  //Met la largeur de trait a 10
  cairo_set_line_width (cr, 5.0);
  //Tracer la ligne
  cairo_stroke(cr);

}

void destroy(){
  //Liberation du contexte
  cairo_destroy(cr);
  //Liberation de la surface
  cairo_surface_destroy(pdf_surface);
}


int* length_test(int i, int* tab){
  if(i == 0)
    tab = malloc(4*sizeof(int*));
  else
    if(i%4 == 0)
      tab = realloc(tab, 2*i*sizeof(*tab));
  
  return tab;
}

void set_draw(Point p1, Point p2){
  
  if(!cr){
    //Creation de la surface pdf associee au fichier ex1.pdf
    pdf_surface = cairo_pdf_surface_create("test.pdf",250, 250);

    //Creation du contexte cairo associe a la surface
    cr = cairo_create(pdf_surface);
  }

  printf("P1 %d, %d \n", p1->x, p1->y);
  printf("P2 %d, %d \n", p2->x, p2->y);

  draw_line(cr, p1, p2);

}

void draw(){
  int i;
  for(i=0; i<tab_length;i++)
  printf("%d\n", pos_tab[i]);

  if(tab_length<4){
      printf("Usage : Draw command need at least two point.\n");
      exit(0);
    }

    Point p1, p2;
    int j = 0;
    p1 = create_point(pos_tab[j], pos_tab[j+1]);
    j+=2;
    p2 = create_point(pos_tab[j], pos_tab[j+1]);
    j+=2;

    set_draw(p1, p2);

    for(j=4; j<tab_length; j+=2){
      p1 = p2;
      p2 = create_point(pos_tab[j], pos_tab[j+1]);

      set_draw(p1, p2);
    }
}

void set_fill(Point* tab_point, int length){

  pdf_surface = cairo_pdf_surface_create("test.pdf",250, 250);
  cr = cairo_create(pdf_surface);
  
  Point p1,p2;
  
  draw_line(cr, tab_point[0], tab_point[1]);

  p1 = tab_point[1];

  int i;
  
  for(i=2; i< length; i++){

    p2 = tab_point[i];

    while(p1->x != p2->x && p1->y != p2->y){
      if(p1->x > p2->x)
        p1->x--;
      else
        p1->x++;
      
      if(p1->y > p2->y)
        p1->y--;
      else
        p1->y++;
      
      draw_line(cr, tab_point[0], p1);
    }
  }
}

void fill(){

  if(tab_length < 4){
      printf("Usage : Fill command need at least two point.\n");
      exit(0);
    }

    Point* tab_point = malloc(sizeof(*tab_point)*(tab_length/2));
    
    int j;

    for(j=0; j < tab_length; j+=2){
      tab_point[j/2] = create_point(pos_tab[j],pos_tab[j+1]);
    }

    set_fill(tab_point, tab_length/2);
}




/* '+' == 1, '-' == 2, '*' == 3, '/' == 4, ')' == 5, debut == 0 
  Principe d'une pile, on empile les opérations qu'on trouve puis on les fait en dépilant.*/

void calc(Stack stack_number, Stack stack_operator){

  int num1, num2, operator, result;

    while (1){
    num2 = pop(&stack_number);

    operator = pop(&stack_operator);

    if(num2 == 0){
      result = 0 + num2;
      push(0, &stack_number);
    }

    num1 = pop(&stack_number);

    if (num1 == 0){
      result = num1 + num2;
      push(0, &stack_number);
    }

    if(operator == 0){
      push(0, &stack_operator);
      break;
    }

    if(operator == 1)
      result = num1 + num2;

    if(operator == 2)
      result = num1 - num2;

    if(operator == 3)
      result = num1 * num2;

    if(operator == 4)
      result = num1 / num2;

    if(operator == 5)
      break;
  }
  
  pos_tab = length_test(tab_length, pos_tab);
  
  pos_tab[tab_length++] = result;
}

void cycle(){
  tab_length += 2;
  pos_tab = length_test(tab_length, pos_tab);

  pos_tab[tab_length-2] = pos_tab[0];
  pos_tab[tab_length-1] = pos_tab[1];
}

void translate(){

  printf("%d %d %d %d\n",pos_tab[tab_length-1], pos_tab[tab_length-2], pos_tab[tab_length-3], pos_tab[tab_length-4]);

  pos_tab[tab_length-2] += pos_tab[tab_length-4];
  pos_tab[tab_length-1] += pos_tab[tab_length-3];
}

void polaire(){

  pos_tab[tab_length-2] = cos(pos_tab[tab_length-1]) * pos_tab[tab_length-2] ;
  pos_tab[tab_length-1] += sin(pos_tab[tab_length-1]) * pos_tab[tab_length-2] ;
}