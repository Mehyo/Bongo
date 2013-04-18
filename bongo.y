
%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "test.h"
<<<<<<< HEAD

=======
	int tab[4];
	int i = 0;
>>>>>>> 3e7b505f56bb1fdcccc2dd0ed969bb11410ab170
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

<<<<<<< HEAD
num : NUMBER {printf(" {TEST %d} ", NUMBER);}
=======
num : NUMBER {tab[i] = $$; i++;}
>>>>>>> 3e7b505f56bb1fdcccc2dd0ed969bb11410ab170
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