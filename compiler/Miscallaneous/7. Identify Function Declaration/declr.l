%{
#include"y.tab.h"
%}

letter [a-zA-Z]
digit [0-9]
id {letter}+({digit}|{letter})*

%%
void {return RTYPE;}
int {return RTYPE;}
float {return RTYPE;}
char {return RTYPE;}
"(" {return LPAR;}
")" {return RPAR;}
"*" {return STAR;}
";" {return SEMICOLON;}
"," {return COMMA;}
{id} {return ID;}
\n {return 0;}
[ \t] {};
. {return yytext[0];}
%%

int yywrap(void){
    return 1;
}