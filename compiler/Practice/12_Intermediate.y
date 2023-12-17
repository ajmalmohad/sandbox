%{
    #include <stdio.h>
    char p = 'A';
    int valid = 1;
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

int main(int argc, char **argv)
{
    yyparse();
    if (valid) printf("Valid\n");
    return 0;
}

int yyerror(char *s){
    printf("Invalid\n");
    valid = 0;
    return 0;
}