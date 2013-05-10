#ifndef _VARIABLE_H_
#define _VARIABLE_H_

struct variable
{
  char* name;
  int* element;
  int taille_tab;
};
typedef struct variable * Variable;

int* point_tab;
int nb_element_point;
int size_point;

Variable* var_tab;
int nb_element_variable;
int size_var;

int* create_tab_point(int* t);
void add_variable(Variable v);
void add_point(int entier);
Variable create_variable(char* name, int* tab_element);
void toStringVar(Variable v);

void clean_tab();

#endif