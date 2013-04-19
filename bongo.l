%{
#include "bongo.tab.h"
%}

%%

"(" {return OPEN;}
")" {return CLOSE;}

"draw " {return DRAW;}
"fill " {return FILL;}

"--" {return SEPARATOR;}

"+" {return PLUS;}
"/" {return DIVID;}
"-" {return MINUS;}
"*" {return FOIS;}

[0-9]+ {yylval = atoi(yytext); return NUMBER;}

"," {return COMMA;}
":" {return DOUBLE;}

";" {return TERM;}

%%

