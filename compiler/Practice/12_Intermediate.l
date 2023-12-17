%{
#include "y.tab.h"
%}

%%
[0-9]+ { yylval.dval = (*yytext); return NUM; }
[ \t\n] return 0;
. return yytext[0];
%%

int yywrap(void) {
    return 1;
}