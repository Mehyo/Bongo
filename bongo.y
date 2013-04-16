%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "test.h"
	int tab[4];
	int i = 0;
	void yyerror(char* s);
%}

%token DRAW SEPARATOR OPEN CLOSE COMMA NUMBER TERM

%%

draw : DRAW point TERM
	;

sep : SEPARATOR point
	| {}
	;

point : OPEN num COMMA num CLOSE sep
	;

num : NUMBER {tab[i] = $$; i++;}
	;

%%


void yyerror(char* s)
{
	printf("%s \n", s);
}

int main(void)
{
	yyparse();
	draw(tab[0], tab[1], tab[2], tab[3]);
	
	return EXIT_SUCCESS;
}