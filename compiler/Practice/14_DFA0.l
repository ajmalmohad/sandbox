%s A B C DEAD

%%
<INITIAL>1 BEGIN A;
<INITIAL>0 BEGIN B;
<INITIAL>[^01\n] BEGIN DEAD;
<INITIAL>\n BEGIN INITIAL; {printf("Not Accepted: Even 1s and Even 0s\n");}

<A>1 BEGIN INITIAL;
<A>0 BEGIN C;
<A>[^01\n] BEGIN DEAD;
<A>\n BEGIN INITIAL; {printf("Not Accepted: Odd 1s and Even 0s\n");}

<B>1 BEGIN C;
<B>0 BEGIN INITIAL;
<B>[^01\n] BEGIN DEAD;
<B>\n BEGIN INITIAL; {printf("Not Accepted: Even 1s and Odd 0s\n");}

<C>1 BEGIN B;
<C>0 BEGIN A;
<C>[^01\n] BEGIN DEAD;
<C>\n BEGIN INITIAL; {printf("Accepted: Odd 1s and Odd 0s\n");}

<DEAD>[^01\n] BEGIN DEAD;
<DEAD>\n BEGIN INITIAL; {printf("Not Accepted: Dead State\n");}
%%

int main()
{
    yylex();
    return 0;
}