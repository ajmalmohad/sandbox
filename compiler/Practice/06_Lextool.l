%{
#include <stdio.h>
int COMMENT = 0;
%}

identifier [a-zA-Z][a-zA-Z0-9]*

%%
"/*" {COMMENT = 1; printf("Comment starts\n");}
"*/" {COMMENT = 0; printf("Comment ends\n");}
#.* {if(!COMMENT) printf("%s is a preprocessor directive\n", yytext);}
int|float|char|double|void|long|short|signed|unsigned|struct|union|enum|typedef|static|extern|register|auto|const|volatile|sizeof|return|continue|break|goto|if|else|switch|case|default|for|do|while {if(!COMMENT) printf("%s is a keyword\n", yytext);}
{identifier}(\(.*\)) {if(!COMMENT) printf("%s is a function\n", yytext);}
\{ {if(!COMMENT) printf("Block starts\n");}
\} {if(!COMMENT) printf("Block ends\n");}
{identifier}(\[[0-9]*\])? {if(!COMMENT) printf("%s is an identifier\n", yytext);}
[0-9]+ {if(!COMMENT) printf("%s is a number\n", yytext);}
\".*\" {if(!COMMENT) printf("%s is a string\n", yytext);}
= {if(!COMMENT) printf("= is an assignment operator\n");}
\+|-|\*|\/|% {if(!COMMENT) printf("%s is an arithmetic operator\n", yytext);}
\<|\>|\>=|\<=|\==|\!= {if(!COMMENT) printf("%s is a relational operator\n", yytext);}
[ \t\n] {}
. {}
%%

int main(int argc, char *argv[])
{
    yyin = fopen("06_Input.txt", "r");
    yylex();
    fclose(yyin);
    return 0;
}