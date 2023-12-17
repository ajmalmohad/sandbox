#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isSpace(char ch){
    if(ch == ' ' || ch == '\t' || ch == '\n'){
        return 1;
    }
    return 0;
}

int isOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '='){
        return 1;
    }
    return 0;
}

int isKeyword(char buffer[]){
    char keywords[][10] = {"auto", "break", "case", "char", "const", "continue", "default", "do",
                             "double", "else", "enum", "extern", "float", "for", "goto", "if",
                             "int", "long", "register", "return", "short", "signed", "sizeof", "static",
                             "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
    int flag = 0;
    for(int i = 0; i < (sizeof keywords)/10; i++){
        if(strcmp(keywords[i], buffer) == 0){
            flag = 1;
            break;
        }
    }
    return flag;
}

int main(){
    FILE *fp = fopen("05_Input.txt", "r");;
    if(fp == NULL){
        printf("File not found!\n");
        exit(1);
    }

    char ch, lexeme[20], idx = 0;
    while((ch = fgetc(fp)) != EOF){
        if(isOperator(ch)){
            printf("%c is an operator\n", ch);
        }
        else if(isalnum(ch)){
            lexeme[idx++] = ch;
        }
        else if (isSpace(ch) && idx > 0){
            lexeme[idx] = '\0';
            idx = 0;
            if(isKeyword(lexeme)){
                printf("%s is a keyword\n", lexeme);
            }else{
                printf("%s is an identifier\n", lexeme);
            }
        }
    }

    fclose(fp);
}