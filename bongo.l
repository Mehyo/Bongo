%{
#include "bongo.tab.h"
%}

%%

"(" {return OPEN;}
")" {return CLOSE;}

"draw " {return DRAW;}
"fill " {return DRAW;}

"--" {return SEPARATOR;}

[0-9]+ {ECHO; NUMBER == yytext[0]; return NUMBER;}

"," {return COMMA;}

";" {return TERM;}

%%

