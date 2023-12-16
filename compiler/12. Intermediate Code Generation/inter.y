%{
#include <stdio.h>
#include <stdlib.h>
char p = 'A';
%}

%union { char dval; }
%token NUM sign
%left '+' '-'
%left '*' '/'
%type <dval> S 
%type <dval> E

%%
S: E { printf("%c\n", $$); }
E: NUM {} 
| E '+' E { printf("%c = %c+%c\n", p, $1, $3); $$ = p; p++; }
| E '-' E { printf("%c = %c-%c\n", p, $1, $3); $$ = p; p++; }
| E '*' E { printf("%c = %c*%c\n", p, $1, $3); $$ = p; p++; }
| E '/' E { printf("%c = %c/%c\n", p, $1, $3); $$ = p; p++; }
%%

int main(int argc, char **argv){   
    printf("Enter the expression: ");
    yyparse();
    printf("The expression is valid\n");
    return 0;
}

int yyerror(char *s){
    printf("The expression is invalid \n");
    exit(0);
}