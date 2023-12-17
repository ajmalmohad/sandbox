%{
#include <stdio.h>
int lines = 0, chars = 0, words = 0;
%}

%%
[a-zA-Z0-9] { chars++; }
[\t ]+ { words++; }
\n { lines++; words++; }
. {}
%%

int main(){
    freopen("02_Input.txt", "r", stdin);
    yylex();
    printf("Lines: %d\nWords: %d\nChars: %d\n", lines, words, chars);
    return 0;
}