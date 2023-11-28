%{
#include <stdio.h>
int comment = 0;
%}

identifier [a-zA-Z][a-zA-Z0-9]*

%%
"/*" {comment=1; printf("%s COMMENT starts:\n", yytext);}
"*/" {comment=0; printf("%s COMMENT ends\n", yytext);}
#.* {if(!comment) printf("%s is a preprocessor directive\n", yytext);}
int|float|char|double|if|else|void {if(!comment) printf("%s is a keyword\n", yytext);}
{identifier}(\(.*\)) {if(!comment) printf("%s FUNCTION: \n", yytext);}
\{ {if(!comment) printf("Block starts: \n");}
\} {if(!comment) printf("Block ends \n");}
{identifier}(\[[0-9]*\])? {if(!comment) printf("%s is an identifier \n", yytext);}
\".*\" {if(!comment) printf("%s is a string \n", yytext);}
[0-9]+ {if(!comment) printf("%s is a number \n", yytext);}
= {if(!comment) printf("%s is an assignment operator \n", yytext);}
\*|\-|\+|\\ {if(!comment) printf("%s is an operator \n", yytext);}
\<=|\>=|\<|\>|== {if(!comment) printf("%s is a relational operator \n", yytext);}
. {}
%%

int main(int argc, char* argv[]){
	FILE *file = fopen("input.txt", "r");
	if(!file){
		printf("Unable to open file\n");
		return 0;
	}
	
	yyin = file;
	yylex();
}
