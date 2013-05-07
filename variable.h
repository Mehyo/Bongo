#ifndef _VARIABLE_H_
#define _VARIABLE_H_

struct variable
{
  char* name;
  int* element;
};
typedef struct Variable* variable;

Variable* pos_tab;
char* name;

Variable create_variable(char* name, int* tab_element);
#endif