%{
	#include <stdio.h>
	int valid = 1;
%}

%token NUMBER ALPHA
%left '+''-''*''/''('')'

%%
expr: '+'expr | '-'expr | '(' expr ')'
    | expr '+' expr | expr '-' expr
    | expr '*' expr | expr '/' expr
    | NUMBER | ALPHA;
%%

int main(){
	printf("Enter an arithmetic expression: \n");
	yyparse();
	if(valid) printf("\n It is a valid arithmetic!");
}

int yyerror(){
	printf("\nIts not a valid arithmetic!");
	valid = 0;
	return 0;
}
