%{
#include "bongo.tab.h"
%}

%%

[A-Za-z0-9] {yylval = yytext; return VARIABLE;}

"(" {return OPEN;}
")" {return CLOSE;}

"draw " {return DRAW;}
"fill " {return FILL;}

"--" {return SEPARATOR;}

"cycle" {return CYCLE;}

"+" {return PLUS;}
"/" {return DIVID;}
"-" {return MINUS;}
"*" {return FOIS;}

[0-9]+ {yylval = atoi(yytext); return NUMBER;}

"," {return COMMA;}
":" {return DOUBLE;}

";" {return TERM;}

[[:space:]]*"="[[:space:]]* {return EQUAL;}

\n {return LINE;}

%%

