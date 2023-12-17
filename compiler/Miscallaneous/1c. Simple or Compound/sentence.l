%{
#include<stdio.h>
int flag=0;
%}

%%
printf("Enter the sentence\n");
[\t ]+ ;
and|or|nevertheless|inspite|because flag=1;
\n { };
. { };
%%

void main(){
    yylex();
    if(flag==1){
        printf("The sentence is a compound sentence\n");
    } else {
        printf("The sentence is a simple sentence\n");
    }
}

int yywrap(){
    return 1;
}