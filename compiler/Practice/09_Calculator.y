%{
    #include <stdio.h>
    int valid = 1;
%}

%token NUMBER ID;
%left '+' '-'
%left '*' '/'
%left '(' ')'

%%
S: E {printf("Result: %d\n", $$);}
E: E '+' E {$$ = $1 + $3;}
 | E '-' E {$$ = $1 - $3;}
 | E '*' E {$$ = $1 * $3;}
 | E '/' E {$$ = $1 / $3;}
 | '(' E ')' {$$ = $2;}
 | NUMBER {$$ = $1;}
 | ID {$$ = $1;}
%%

int main(int argc, char **argv) {
    yyparse();
    if (valid) {
        printf("Expression is valid\n");
    }
    return 0;
}

int yyerror(char *s) {
    printf("Expression is invalid\n");
    valid = 0;
    return 0;
}