#include <stdio.h>
#include <string.h>

void main(){
    char intermediateCode[10][30], singleInstruction[20], operation[10];
    int instructionIndex = 0;

    printf("\nEnter the intermediate code (terminated by exit):\n");
    do{
        scanf("%s", intermediateCode[instructionIndex]);
    } while (strcmp(intermediateCode[instructionIndex++], "exit") != 0);

    printf("\nTarget code generation");
    printf("\n**********************");

    instructionIndex = 0;

    do{
        strcpy(singleInstruction, intermediateCode[instructionIndex]);
        switch (singleInstruction[3]){
        case '+':
            strcpy(operation, "ADD");
            break;
        case '-':
            strcpy(operation, "SUB");
            break;
        case '*':
            strcpy(operation, "MUL");
            break;
        case '/':
            strcpy(operation, "DIV");
            break;
        }
        printf("\nMOV %c,R%d", singleInstruction[2], instructionIndex);
        printf("\n%s %c,R%d", operation, singleInstruction[4], instructionIndex);
        printf("\nMOV R%d,%c", instructionIndex, singleInstruction[0]);
    } while (strcmp(intermediateCode[++instructionIndex], "exit") != 0);
}