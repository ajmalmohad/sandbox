#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void passOne(char label[10], char opcode[10], char operand[10], char code[10], char mnemonic[3])
{
    int locctr, start, length;
    FILE* fp1, * fp2, * fp3, * fp4, * fp5;

    // read mode
    fp1 = fopen("input.txt", "r");
    fp2 = fopen("optab.txt", "r");

    // write mode
    fp3 = fopen("symtab.txt", "w");
    fp4 = fopen("intermediate.txt", "w");
    fp5 = fopen("length.txt", "w");

    // read first line
    fscanf(fp1, "%s\t%s\t%s", label, opcode, operand);

    if (strcmp(opcode, "START") == 0) {
        // convert operand value from string to integer and assign to start                     
        start = atoi(operand);
        locctr = start;

        // write to output file (additional tab space as start will not have any locctr)
        fprintf(fp4, "\t\t%s\t%s\t%s\n", label, opcode, operand);

        // read next line  
        fscanf(fp1, "%s\t%s\t%s", label, opcode, operand);
    }
    else {
        locctr = 0;
    }

    // iterate till end
    while (strcmp(opcode, "END") != 0) {

        // 1. write the readed line to output file with locctr
        fprintf(fp4, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);

        // 2. write to symtab file with values not starting with ** ( ** means there is no label )
        if (strcmp(label, "**") != 0) {
            fprintf(fp3, "%s\t%d\n", label, locctr);
        }

        // 3. read first line from optab (code and mnemonic value)
        fscanf(fp2, "%s\t%s", code, mnemonic);

        // 4. traverse and check till the end of optab file
        while (strcmp(code, "END") != 0) {

            // if opcode in input matches the one in optab, increment locctr by 3
            if (strcmp(opcode, code) == 0) {
                locctr += 3;
                break;
            }

            // read next optab line
            fscanf(fp2, "%s\t%s", code, mnemonic);
        }

        // 5. checking opcode for WORD, RESW, BYTE, RESB keywords and updating locctr

        // WORD -> add 3 to locctr
        if (strcmp(opcode, "WORD") == 0) {
            locctr += 3;
        }

        // RESW -> add 3*operand to locctr
        else if (strcmp(opcode, "RESW") == 0) {
            locctr += (3 * (atoi(operand)));
        }

        // BYTE -> add 1 to locctr 
        else if (strcmp(opcode, "BYTE") == 0) {
            // Calculate the bytes needed and add to locctr ( Exclude C and 2 quotes)
            int length = strlen(operand) - 3;

            // If it is string add length of string to locctr
            if (operand[0] == 'C' || operand[0] == 'c') {
                locctr += length;
            }

            // Else it will be X ( Hexadecimal ), add length/2 to locctr
            else {
                // ( Hexadecimal can store 2 numbers in 1 byte )
                locctr += length / 2;
            }
        }

        // RESB -> add operand to locctr
        else if (strcmp(opcode, "RESB") == 0) {
            locctr += atoi(operand);
        }

        // read next line
        fscanf(fp1, "%s\t%s\t%s", label, opcode, operand);
    }

    // 6. transfer last line to file ( END line )
    fprintf(fp4, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);

    // 7. Close all files
    fclose(fp4);
    fclose(fp3);
    fclose(fp2);
    fclose(fp1);

    // 9. calculate length of program
    length = locctr - start;
    fprintf(fp5, "%d", length);
    fclose(fp5);
    printf("\nThe length of the code : %d\n", length);
}


void display(char filename[10]) {

    // open the file
    printf("\nThe contents of %s :\n\n", filename);
    FILE *fp =  fopen(filename, "r");

    // read and print all characters
    char str = fgetc(fp);
    while (str != EOF) {
        printf("%c", str);
        str = fgetc(fp);
    }

    // close the file
    fclose(fp);
}


int main()
{
    // strings for input from assembly program
    char label[10], opcode[10], operand[10];

    // strings for input from optab
    char code[10], mnemonic[3];

    // do pass 1 for 2 pass assembler
    passOne(label, opcode, operand, code, mnemonic);

    // display output files
    display("input.txt");
    display("intermediate.txt");
    display("symtab.txt");

    return 0;
}






















/*
input.txt
---------
**	START	2000
**	LDA	FIVE
**	STA	ALPHA
** 	LDCH 	CHARZ
** 	STCH 	C1
ALPHA 	RESW 	2
FIVE 	WORD 	5
CHARZ 	BYTE 	C'Z'
C1 	RESB 	1
** 	END	**
optab.txt
---------
LDA 03
STA	0f
LDCH	53
STCH	57
END	*
-----------------------------
symtab.txt
----------
ALPHA   2012
FIVE    2018
CHARZ   2021
C1      2022
intermediate.txt
----------------
        **      START   2000
2000    **      LDA     FIVE
2003    **      STA     ALPHA
2006    **      LDCH    CHARZ
2009    **      STCH    C1
2012    ALPHA   RESW    2
2018    FIVE    WORD    5
2021    CHARZ   BYTE    C'Z'
2022    C1      RESB    1
2023    **      END     **
length.txt
----------
23
*/