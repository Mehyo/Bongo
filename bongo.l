%{
#include "bongo.tab.h"
%}


%%


"(" {ECHO; return OPEN;}
")" {ECHO; return CLOSE;}

"draw " {ECHO; return DRAW;}
"fill " {ECHO; return DRAW;}

"--" {ECHO; return SEPARATOR;}

[0-9]+ {ECHO; return NUMBER;}

"," {ECHO; return COMMA;}

";" {ECHO; return TERM;}

%%

