
%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "draw.h"
	#include "point.h"

	int* tab;
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

num : NUMBER {tab = length_test(i, tab); tab[i] = $$; i++;}
	;

%%


void yyerror(char* s)
{
	printf("%s \n", s);
}

int main(void)
{
	Point p1, p2;
	int j = 0;

	yyparse();

	p1 = create_point(tab[j], tab[j+1]);
	j+=2;
	p2 = create_point(tab[j], tab[j+1]);
	j+=2;

	draw(p1, p2);
	
	while(j<i){
		p1 = p2;
		p2 = create_point(tab[j], tab[j+1]);
		draw(p1, p2);
		j+=2;
	}

	destroy();

	
	return EXIT_SUCCESS;
}