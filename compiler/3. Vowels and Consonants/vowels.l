%{
	#include <stdio.h>
	int vowels=0, consonants=0;
%}

%%
[aeiouAEIOU] {vowels++;}
[a-zA-Z] {consonants++;}
"\n" {printf("Vowels=%d\nConsonants=%d\n", vowels, consonants);exit(0);}
. {}
%%

int main(int argc, char *argv[]){
	printf("Enter a sentence\n");
	yylex();
}
