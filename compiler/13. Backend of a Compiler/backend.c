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
    printf("\n********************\n");

    instructionIndex = 0;

    while (strcmp(intermediateCode[instructionIndex], "exit") != 0){
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
        printf("MOV R%d,%c\n", instructionIndex, singleInstruction[2]);
        printf("%s R%d,%c\n", operation, instructionIndex, singleInstruction[4]);
        printf("MOV %c,R%d\n", singleInstruction[0], instructionIndex);
        instructionIndex++;
    }
}