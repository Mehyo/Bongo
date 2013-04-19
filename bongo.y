
%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "draw.h"
	#include "point.h"

	int is_fill = 0;

	void yyerror(char* s);
%}

%token DRAW SEPARATOR OPEN CLOSE COMMA DOUBLE NUMBER TERM FOIS DIVID PLUS MINUS FILL CYCLE

%%

start : fill start
	| draw start
	| {}
	;

fill : FILL point TERM {is_fill = 1;}
	;

draw : DRAW point TERM {}
	;

sep : SEPARATOR point
	| {}
	;

point : OPEN op COMMA op CLOSE sep
	| OPEN op DOUBLE op CLOSE sep
	| CYCLE sep {pos_tab = length_test(tab_length+2, pos_tab); pos_tab[tab_length] = pos_tab[0]; pos_tab[tab_length+1] = pos_tab[1]; tab_length+=2;}
	;

op : OPEN op CLOSE
	| op FOIS NUMBER {pos_tab [ tab_length-1 ] *= $3;}
	| op DIVID NUMBER {pos_tab [ tab_length-1 ] /= $3;}
	| op PLUS NUMBER {pos_tab [ tab_length-1 ] += $3;}
	| op MINUS NUMBER {pos_tab [ tab_length-1 ] -= $3;}
	| NUMBER FOIS op {pos_tab [ tab_length-1 ] *= $3;}
	| NUMBER DIVID op {pos_tab [ tab_length-1 ] /= $3;}
	| NUMBER PLUS op {pos_tab [ tab_length-1 ] += $3;}
	| NUMBER MINUS op {pos_tab [ tab_length-1 ] -= $3;}
	| num
	;

num : NUMBER {pos_tab = length_test(tab_length, pos_tab); pos_tab[tab_length] = $$; tab_length++;}
	;



%%


void yyerror(char* s)
{
	printf("%s \n", s);
}

int main(void)
{
	yyparse();

	if(!is_fill)
		draw();
	
	else
		fill();

	destroy();

	return EXIT_SUCCESS;
}