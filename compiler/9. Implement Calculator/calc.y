%{
	#include <stdio.h>
%}

%token NUMBER ID;
%left '+' '-'
%left '*' '/'

%%
E:T {
	printf("result = %d\n", $$);
	return 0;
}
T: 
T'+'T {$$=$1+$3;}  |
T'-'T {$$=$1-$3;}  |
T'*'T {$$=$1*$3;}  |
T'/'T {$$=$1/$3;}  |
'('T')' {$$=$2;}   |
'-'NUMBER {$$=-$2;}|
'-'ID {$$=-$2;}    |
NUMBER {$$=$1;}    |
ID {$$=$1;};
%%

int main(){
	printf("Enter the expresssion\n");
	yyparse();
}

int yyerror(){
	printf("Invalid expression\n");
}
