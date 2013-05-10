#include <stdlib.h>
#include <stdio.h>
#include "draw.h"
#include "variable.h"

int* create_tab_point(int* t){
	t = (int*) malloc(10*sizeof(int));
	nb_element_point = 0;
	size_point = 10;
	return t;
}

void add_point(int entier){
	if(nb_element_point == size_point){
		size_point *= 2;
		point_tab = realloc(point_tab, size_point*sizeof(int));
		point_tab[nb_element_point] = entier;
		nb_element_point++;
	}

	else{
		point_tab[nb_element_point] = entier;
		nb_element_point++;

	}
}

void create_tab_var(){
	var_tab = malloc(10*sizeof(Variable));
	nb_element_variable = 0;
	size_var = 10;
}

void add_variable(Variable v){
	if(nb_element_variable == size_var){
		size_var *= 2;
		var_tab = realloc(var_tab, size_var*sizeof(Variable));
		var_tab[nb_element_variable] = v;
		nb_element_variable++;
	}

	else{
		var_tab[nb_element_variable] = v;
		nb_element_variable++;
	}
}


Variable create_variable(char* name, int* tab_element){

	Variable v = malloc(sizeof(*v));

	v->name = name;

	v->element = tab_element;
	v->taille_tab = nb_element_point;
	
	return v;
}

void toStringPoint(int* tab){
	int i;
	for(i = 0; i<nb_element_point; i++)
		printf("\nPoint = \n", tab[i]);
}

void toStringVar(Variable v){
	int i;
	for(i = 0; i<v->taille_tab; i++)
		printf("\nNom Variable = %s\n Tab = %d, ",v->name, v->element[i]);
}


void clean_tab(){
	// int i;
	// for (i=0; i< nb_element_point; i++)
	// 	point_tab[i] = NULL;
	// nb_element_point = 0;
}