#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fp1, *fp2, *fp3;
    fp1 = fopen("input.txt", "r");
    fp2 = fopen("namtab.txt", "w+");
    fp3 = fopen("deftab.txt", "w+");
    
    char label[10], opcode[10], operand[10];
    fscanf(fp1, "%s%s%s", label, opcode, operand);
    while (strcmp(opcode, "MEND") != 0)
    {
        if(strcmp(opcode, "MACRO") == 0){
            fprintf(fp2, "%s\n", label);
            fprintf(fp3, "%s\t%s\n", label, operand);
        }else{
            fprintf(fp3, "%s\t%s\n", opcode, operand);
        }
        fscanf(fp1, "%s%s%s", label, opcode, operand);
    }
    fprintf(fp3, "%s\n", opcode);

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}