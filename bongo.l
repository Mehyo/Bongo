%{
#include "bongo.tab.h"
%}

%%

"(" {return OPEN;}
")" {return CLOSE;}

"draw " {return DRAW;}
"fill " {return DRAW;}

"--" {return SEPARATOR;}

<<<<<<< HEAD
[0-9]+ {ECHO; NUMBER == yytext[0]; return NUMBER;}
=======
[0-9]+ {ECHO; yylval = atoi(yytext); return NUMBER;}
>>>>>>> 3e7b505f56bb1fdcccc2dd0ed969bb11410ab170

"," {return COMMA;}

";" {return TERM;}

%%

