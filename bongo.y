
%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "draw.h"
	#include "point.h"

	int* tab;
	int i = 0;
	int is_fill = 0;

	void yyerror(char* s);
%}

%token DRAW SEPARATOR OPEN CLOSE COMMA DOUBLE NUMBER TERM FOIS DIVID PLUS MINUS FILL

%%

start : fill
	| draw
	;

fill : FILL point TERM {is_fill = 1;}
	;

draw : DRAW point TERM
	;

sep : SEPARATOR point
	| {}
	;

point : OPEN op COMMA op CLOSE sep
	| OPEN op DOUBLE op CLOSE sep
	;

op : OPEN op CLOSE
	| op FOIS NUMBER {tab[i-1] *= $3;}
	| op DIVID NUMBER {tab[i-1] /= $3;}
	| op PLUS NUMBER {tab[i-1] += $3;}
	| op MINUS NUMBER {tab[i-1] -= $3;}
	| num
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
	yyparse();

	if(!is_fill){

		if(i<4){
			printf("Usage : Draw command need at least two point.\n");
			return 0;
		}

		Point p1, p2;
		int j = 0;

		p1 = create_point(tab[j], tab[j+1]);
		j+=2;
		p2 = create_point(tab[j], tab[j+1]);
		j+=2;

		draw(p1, p2);

		for(int j=0; j<i; j+=2){
			p1 = p2;
			p2 = create_point(tab[j], tab[j+1]);
			draw(p1, p2);
			j+=2;
		}
	}
	else{
		
		if(i<4){
			printf("Usage : Fill command need at least two point.\n");
			return 0;
		}

		Point* tab_point = malloc(sizeof(*tab_point)*(i/2));
		
		for(int j=0; j<i; j+=2){
			tab_point[j/2] = create_point(tab[j], tab[j+1]);
		}

		fill(tab_point, i/2);
	}
	destroy();

	
	return EXIT_SUCCESS;
}