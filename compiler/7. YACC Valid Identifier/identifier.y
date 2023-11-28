%{
	#include <stdio.h>
	int valid=1;
%}

%token digit letter

%%
start : letter s
s : letter s | digit s | ;
%%

int main(){
	printf("Enter a name to tested for identifier: \n");
	yyparse();
	if(valid){
		printf("\n It is a identifier!");
	}
}

int yyerror(){
	printf("\nIts not a identifier!");
	valid=0;
	return 0;
}
