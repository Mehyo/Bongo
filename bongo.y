%{
	#include <stdio.h>
	#include <stdlib.h>

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

num : NUMBER
	;

%%


void yyerror(char* s)
{
	printf("%s \n", s);
}

int main(void)
{
	yyparse();
	return EXIT_SUCCESS;
}