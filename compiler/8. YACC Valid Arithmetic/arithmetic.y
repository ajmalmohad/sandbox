%{
	#include <stdio.h>
	int valid = 1;
%}

%token NUMBER ALPHA
%left '+' '-'
%left '*' '/'
%left '(' ')'

%%
expr: '+'expr | '-'expr | '(' expr ')'
    | expr '+' expr | expr '-' expr
    | expr '*' expr | expr '/' expr
    | NUMBER | ALPHA;
%%

int main(){
	printf("Enter an arithmetic expression: \n");
	yyparse();
	if(valid) printf("It is a valid arithmetic!\n");
}

int yyerror(){
	printf("Its not a valid arithmetic!\n");
	valid = 0;
	return 0;
}
