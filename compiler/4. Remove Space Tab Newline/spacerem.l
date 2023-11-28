%{
	#include <stdio.h>
%}

%%
[\t\n" "] {}
%%

int main(int argc, char* argv[]){
	yyin=fopen("input.txt", "r");
	yylex();
}
