%{
#include <stdio.h>
int valid = 1;
%}

%token NUMBER;
%token LETTER;

%%
S: LETTER E;
E: LETTER S | NUMBER S | NUMBER | ;
%%

int main(int argc, char **argv)
{
    yyparse();
    if(valid) {
        printf("Valid Identifier\n");
    }
    return 0;
}

int yyerror(char *s)
{
    valid = 0;
    printf("Not Valid Identifier \n");
    return 0;
}