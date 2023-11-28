%{
	#include <stdio.h>
	int lines=0, words=0, characters=0;
%}

%%
[a-zA-Z0-9] {characters++;}
" " {words++;}
"\n" {words++; lines++;}
. {}
%%

int main(int argc, char* argv[]) {
	yyin = fopen("input.txt", "r");
	yylex();
	printf("Lines = %d\n", lines);
	printf("Words = %d\n", words);
	printf("Characters = %d\n", characters);
}
