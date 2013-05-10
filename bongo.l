%{
#include "bongo.tab.h"
#include <string.h> 
char* toto;
%}

%%

"draw " {ECHO;return DRAW;}
"fill " {ECHO;return FILL;}

[A-Za-z0-9]+[[:space:]]+ {ECHO; yylval.name = strdup(yytext);return VARIABLE;}

"(" {ECHO;return OPEN;}
")" {ECHO;return CLOSE;}



"--" {ECHO;return SEPARATOR;}

"cycle" {ECHO;return CYCLE;}

"+" {ECHO;return PLUS;}
"/" {ECHO;return DIVID;}
"-" {ECHO;return MINUS;}
"*" {ECHO;return FOIS;}

[0-9]+ {ECHO;yylval.entier = atoi(yytext); return NUMBER;}

"," {ECHO;return COMMA;}
":" {ECHO;return DOUBLE;}

";" {ECHO;return TERM;}

"="[[:space:]]* {ECHO;return EQUAL;}

\n {return LINE;}

%%

