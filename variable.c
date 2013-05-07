#include <stdlib.h>
#include <stdio.h>
#include "draw.h"
#include "variable.h"

Variable create_variable(char* name, int* tab_element);
{
	Variable v = malloc(sizeof(*v));

	v->name = name;

	int i;
	for(i = tab_length ; i == 0; i--){
		if(tab_length[i] == 5000)
			break;
	}

	v->elements = malloc(sizeof(int*)*i);

	int j;

	for(i; i< tab_length; i++){
		v->elements[j] == tab_element[i];
		j++;
	}
	
	return v;
}