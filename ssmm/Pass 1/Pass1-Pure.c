#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void passOne(char label[10],char opcode[10],char operand[10],char code[10],char mnuemonic[10]){

    FILE *fp1, *fp2, *fp3, *fp4, *fp5;
    fp1 = fopen("input.txt", "r");
    fp2 = fopen("optab.txt", "r");
    fp3 = fopen("intermediate.txt", "w");
    fp4 = fopen("symtab.txt", "w");
    fp5 = fopen("length.txt", "w");

    fscanf(fp1, "%s\t%s\t%s", label, opcode, operand);

    int start, locctr;
    if (strcmp(opcode, "START") == 0){
        start = atoi(operand);
        locctr = start;
        fprintf(fp3, "%s\t%s\t%s\n", label, opcode, operand);
        fscanf(fp1, "%s\t%s\t%s", label, opcode, operand);
    }else{
        locctr = 0;
    }

    while (strcmp(opcode, "END") != 0){

        fprintf(fp3, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);
        if(strcmp(label, "**") != 0) fprintf(fp4, "%s\t%d\n", label, locctr);

        fscanf(fp2, "%s\t%s", code, mnuemonic);
        while(strcmp(code, "END") != 0){
            if(strcmp(code, opcode) == 0)  { locctr += 3; break; }
            fscanf(fp2, "%s\t%s", code, mnuemonic);
        }

        if(strcmp(opcode, "RESB") == 0) locctr += atoi(operand);
        else if(strcmp(opcode, "RESW") == 0) locctr += 3*atoi(operand);
        else if(strcmp(opcode, "WORD") == 0) locctr += 3;
        else if(strcmp(opcode, "BYTE") == 0){
            int length = strlen(operand) - 3;
            if(operand[0] == 'C' || operand[0] == 'c') locctr += length;
            else locctr += length/2;
        }

        fscanf(fp1, "%s\t%s\t%s", label, opcode, operand);
    }
    
    fprintf(fp3, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);
    int length = locctr-start;
    fprintf(fp5, "%d\n", length);

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);
}

int main(){
    char label[10], opcode[10], operand[10];
    char mnuemonic[10], code[10];
    passOne(label, opcode, operand, code, mnuemonic);
    return 0;
}