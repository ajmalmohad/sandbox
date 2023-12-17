%{
#include <stdio.h>
#include <stdbool.h>
int operator = 0, started = false;
float result = 0, temp = 0;
%}

%%
[0-9]*("."[0-9]*)? { 
    started = true; 
    temp = atof(yytext);
    if(operator == 0) result = temp;
    else if(operator == 1) result += temp;
    else if(operator == 2) result -= temp;
    else if(operator == 3) result *= temp;
    else if(operator == 4) result /= temp;
}
"+" { operator = 1; }
"-" { operator = 2; }
"*" { operator = 3; }
"/" { operator = 4; }
\n {
    if(started) {
        printf("= %f\n", result);
        result = 0;
        operator = 0;
        started = false;
    }
}
[ \t] {}
. { printf("Error\n"); }
%%

int main(int argc, char **argv) {
    yylex();
    return 0;
}