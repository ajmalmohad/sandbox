%{
#include <stdio.h>
#include <ctype.h>
%}

%%
[a-z] { printf("%c", toupper(yytext[0])); }
[A-Z0-9] { printf("%c", yytext[0]); }
\n {}
. {}
%%

int main(int argc, char **argv){
    freopen("10_Input.txt", "r", stdin);
    freopen("10_Output.txt", "w", stdout);
    yylex();
    return 0;
}

int yywrap(){
    return 1;
}