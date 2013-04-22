%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "stack.h"
	#include "draw.h"
	#include "point.h"
	#include "bongo.tab.h"

	int is_fill, is_translate;

	void yyerror(char* s);
%}

%token DRAW SEPARATOR OPEN CLOSE COMMA DOUBLE NUMBER TERM FOIS DIVID PLUS MINUS FILL CYCLE

%%

start : fill
	| draw
	;

fill : FILL point TERM {is_fill = 1;}
	;

draw : DRAW point TERM 
	;

sep : SEPARATOR point
	|
	;

point : OPEN valeur COMMA valeur CLOSE sep
	| OPEN valeur DOUBLE valeur CLOSE sep {polaire();}
	| CYCLE sep {cycle();}
	| PLUS OPEN valeur COMMA valeur CLOSE sep {translate();}
	;

valeur : OPEN {push(6, &stack_operator);} valeur CLOSE {calc(stack_number, stack_operator);}
  	| num {calc(stack_number, stack_operator);}
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
	stack_number = create_stack(0);
	stack_operator = create_stack(0);
	yyparse();

	if(!is_fill)
		draw();
	
	else
		fill();

	destroy();

	return EXIT_SUCCESS;
}