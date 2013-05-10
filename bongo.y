%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "stack.h"
	#include "variable.h"
	#include "draw.h"
	#include "point.h"
	#include "bongo.tab.h"
	#include <string.h>
	char * nomVariable;
	int i;



	int is_fill, is_draw,is_translate, is_var = 0;

	void yyerror(char* s);
%}

%union {
	char *name;
	int entier;
} 

%token DRAW SEPARATOR OPEN CLOSE COMMA DOUBLE TERM FOIS DIVID PLUS MINUS FILL CYCLE LINE EQUAL


%token <name> VARIABLE
%type <entier> num
%token <entier> NUMBER

%%

start : {is_var = 1;} variable line {is_var = 0;}
	| {is_var = 0;} fill line 
	| {is_var =0;} draw line
	;

variable : VARIABLE EQUAL point TERM { /* add_variable(create_variable($1, point_tab)); clean_tab(); */ }
	|
	;


line : LINE  {if(is_var == 0) push(6, &stack_operator);} start
	|
	;

fill : FILL point TERM {is_fill = 1;}
	;

draw : DRAW point {} TERM {is_draw = 1;}
	;

sep : SEPARATOR point
	|
	;

point : OPEN valeur COMMA valeur CLOSE sep 
	| OPEN valeur DOUBLE valeur CLOSE sep {polaire(is_var);}
	| CYCLE {cycle(is_var);} sep
	| PLUS OPEN valeur COMMA valeur CLOSE {translate(is_var);} sep 
	;

valeur : OPEN valeur CLOSE {calc(is_var);}
  	| num {calc(is_var);}
	;

num : NUMBER operator {push($$, &stack_number);}
	| MINUS NUMBER  {push((-1)*$2, &stack_number);}
	;

operator : FOIS valeur {push(3, &stack_operator);}
	| DIVID valeur {push(4, &stack_operator);}
	| PLUS valeur {push(1, &stack_operator);}
	| MINUS valeur {push(2, &stack_operator);}
	|
	;

%%


void yyerror(char* s)
{
	printf("%s \n", s);
}

int main(void)
{
	stack_number = create_stack(-1);
	stack_operator = create_stack(0);
	// point_tab = create_tab_point(point_tab);
	// create_tab_var();
	

	yyparse();


	if(is_draw)
		draw();
	
	if(is_fill)
		fill();

	destroy();

	return EXIT_SUCCESS;
}