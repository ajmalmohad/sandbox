#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void passTwo(char label[10],char opcode[10],char operand[10],char mnuemonic[10],char code[10]){
    FILE *fp1, *fp2, *fp3, *fp4, *fp5;
    fp1 = fopen("intermediate.txt", "r");
    fp2 = fopen("symtab.txt", "r");
    fp3 = fopen("optab.txt", "r");
    fp4 = fopen("output.txt", "w");
    fp5 = fopen("objectcode.txt", "w");

    int finaladdr, prevaddr, address, start;

    fscanf(fp1, "%s\t%s\t%s", label, opcode, operand);
    while (strcmp(opcode, "END") != 0){
        prevaddr = address;
        fscanf(fp1, "%d\t%s\t%s\t%s", &address, label, opcode, operand);
    }
    finaladdr = address;
    rewind(fp1);

    fscanf(fp1, "%s\t%s\t%s", label, opcode, operand);
    if(strcmp(opcode, "START") == 0){
        fprintf(fp4, "%s\t%s\t%s\n", label, opcode, operand);
        fprintf(fp5, "H^%s^00%s^00%d\n", label, operand, finaladdr);

        fscanf(fp1, "%d\t%s\t%s\t%s",&address, label, opcode, operand);
        start = address;
        int length = prevaddr - start;
        fprintf(fp5, "T^00%d^%d", start, length);
    }

    while (strcmp(opcode, "END") != 0){
        if (strcmp(opcode, "BYTE") == 0){
            fprintf(fp4, "%d\t%s\t%s\t%s\t", address, label, opcode, operand);
            char buffer[10];
            int len = strlen(operand);
            fprintf(fp5, "^");
            for (int i = 2; i < len-1; i++){
                itoa(operand[i],buffer,16);
                fprintf(fp5, "%s", buffer);
                fprintf(fp4, "%s", buffer);
            }
            fprintf(fp4, "\n");
        }else if (strcmp(opcode, "WORD") == 0){
            char buffer[10];
            itoa(atoi(operand),buffer,10);
            fprintf(fp4, "%d\t%s\t%s\t%s\t0000%s\n", address, label, opcode, operand, buffer);
            fprintf(fp5, "^0000%s", buffer);
        }else if (strcmp(opcode, "RESW") == 0 || strcmp(opcode, "RESB") == 0 ){
            fprintf(fp4, "%d\t%s\t%s\t%s\n", address, label, opcode, operand);
        }else{
            
            fscanf(fp3, "%s\t%s", mnuemonic, code);
            while (strcmp(opcode,"END") != 0){
                if(strcmp(opcode, mnuemonic) == 0) break;
                fscanf(fp3, "%s\t%s", mnuemonic, code);
            }
            rewind(fp3);

            if(strcmp(operand, "COPY") == 0){
                fprintf(fp4, "%d\t%s\t%s\t%s0000\n", address, label, opcode, operand, code);
            }else{
                char symbol[10];
                int symaddr;
                rewind(fp2);
                fscanf(fp2, "%s\t%d", symbol, &symaddr);
                while(strcmp(operand, symbol) != 0)  fscanf(fp2, "%s\t%d", symbol, &symaddr);
                fprintf(fp4, "%d\t%s\t%s\t%s\t%s%d\n", address, label, opcode, operand, code, symaddr);
                fprintf(fp5, "^%s%d", code, symaddr);
            }
        }

        fscanf(fp1, "%d\t%s\t%s\t%s",&address, label, opcode, operand);
    }

    fprintf(fp4, "%d\t%s\t%s\t%s",address, label, opcode, operand);
    fprintf(fp5, "\nE^00%d\n", start);

    fclose(fp4);
    fclose(fp3);
    fclose(fp2);
    fclose(fp1);
    fclose(fp5);
}


int main(){
    char label[10], opcode[10], operand[10];
    char mnuemonic[10], code[10];
    passTwo(label, opcode, operand, mnuemonic, code);
    return 0;
}