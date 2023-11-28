%{
	#include <stdio.h>
	#include <ctype.h>
	FILE *inputfile, *outputfile;
%}

%%
[a-z] fprintf(outputfile, "%c", toupper(yytext[0]));
. fprintf(outputfile, "%c", yytext[0]);
%%

int main() {
	inputfile = fopen("input.txt", "r");
	if(!inputfile) { printf("No input file\n"); return 0; }
	outputfile = fopen("output.txt", "w");
	yyin = inputfile;
	yylex();
}
