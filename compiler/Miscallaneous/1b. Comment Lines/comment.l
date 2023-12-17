%{
#include <stdio.h>
int comments = 0;
%}

%%
"/\*".*"\*/" {comments++;}
"//"(.*) {comments++;}
%%

int main(int argc, char *argv[])
{
    yyin = fopen("input.txt", "r");
    yyout = fopen("output.txt", "w");
    yylex();
    printf("comments: %d\n", comments);
    return 0;
}