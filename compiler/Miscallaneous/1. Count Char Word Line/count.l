%{
#include <stdio.h>
int chars = 0, words = 0, lines = 0;
%}

%%
\n { lines++; }
[^ \t\n]+ { chars+=yyleng; words++; }
[ \t] { }
%%

int main(int argc, char *argv[]){
    yylex();
    printf("Lines: %d\nWords: %d\nChars:%d\n", lines, words, chars);
    return 0;
}
