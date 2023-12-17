%{
    #include <stdio.h>
    int vowels = 0, consonants = 0;  
%}

%%
[aeiouAEIOU] {vowels++;}
[a-zA-Z] {consonants++;}
. {}
%%

int main()
{
    stdin = fopen("03_Input.txt", "r");
    yylex();
    printf("Vowels: %d\nConsonants: %d\n", vowels, consonants);
    return 0;
}