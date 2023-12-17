%{
#include <stdio.h>    
%}

%%
[\t\n ]+ {}
%%

int main(int argc, char **argv){
    stdin = fopen("04_Input.txt", "r");
    yylex();
    return 0;
}