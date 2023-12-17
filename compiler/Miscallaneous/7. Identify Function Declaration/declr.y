%{
    #include <stdio.h>
    int valid = 1;
%}

%token RTYPE LPAR RPAR COMMA SEMICOLON STAR ID

%%
program: | function;
returntype: RTYPE | RTYPE STAR;
arguments: | returntype ID | returntype ID COMMA arguments;
function: returntype ID LPAR arguments RPAR SEMICOLON;
%%

int main(int argc, char **argv)
{
    yyparse();
    if (valid) printf("Valid Declaration\n");
    return 0;
}

int yyerror(char *s){
    printf("Invalid Declaration\n");
    valid = 0;
    return 0;
}