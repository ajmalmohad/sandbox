%{
    #include <stdio.h>
    int valid = 1;
%}

%token NUMBER VARIABLE;
%left '+' '-';
%left '*' '/';
%left '(' ')';

%%
S: E;
E: '-' E 
 | E '+' E
 | E '-' E
 | E '*' E
 | E '/' E
 | '(' E ')'
 | NUMBER
 | VARIABLE;
%%

int main(int argc, char **argv){
    yyparse();
    if(valid){
        printf("Valid Arithmetic\n");
    }
    return 0;
}

int yyerror(char *s){
    printf("Not Valid Arithmetic\n");
    valid = 0;
    return 0;
}