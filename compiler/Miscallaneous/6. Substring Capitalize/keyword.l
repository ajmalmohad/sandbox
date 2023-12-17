%{
#include <stdio.h>
#include <ctype.h>    
%}

%%
int|float|void|return { for(int i = 0; i < yyleng; i++) printf("%c", toupper(yytext[i])); }
%%

int main()
{
    yylex();
    return 0;
}