%{
#include <stdio.h>
#include <ctype.h>  
%}

%%
[a-z] { printf("%c",toupper(yytext[0])); }
[A-Z] { printf("%c",tolower(yytext[0])); }
[ \t]+ { printf(" "); }
. { printf("%c",yytext[0]); }
\n {}
%%

int main(int argc, char **argv){
    yylex();
    return 0;
}