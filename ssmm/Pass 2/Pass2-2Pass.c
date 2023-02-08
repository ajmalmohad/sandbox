#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display(char filename[10]) {

    // open the file
    printf("\nThe contents of %s :\n\n", filename);
    FILE* fp = fopen(filename, "r");

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
    char label[10], opcode[10], operand[10], symbol[10];
    int start, diff, i, len, j = 0;

    // OPTAB
    char mnemonic[15][15] = { "LDA", "STA", "LDCH", "STCH" };
    char code[15][15] = { "33", "44", "53", "57" };

    // file pointers
    FILE* fp1, * fp2, * fp3, * fp4;

    // input files
    fp2 = fopen("symtab.txt", "r");
    fp3 = fopen("intermediate.txt", "r");

    // output files
    fp1 = fopen("output.txt", "w");
    fp4 = fopen("objcode.txt", "w");

    // read first line ( start line has no address )
    fscanf(fp3, "%s\t%s\t%s", label, opcode, operand);

    // find final address ( address where end is ) and the one before it
    int finaladdr, prevaddr, address;
    while (strcmp(opcode, "END") != 0)
    {
        prevaddr = address;
        fscanf(fp3, "%d%s%s%s", &address, label, opcode, operand);
    }
    finaladdr = address;

    // reopen intermediate file
    rewind(fp3);

    // read first line ( start line has no address )
    fscanf(fp3, "\t%s\t%s\t%s", label, opcode, operand);

    // write the header record to object code
    if (strcmp(opcode, "START") == 0)
    {

        // write first line to output file
        fprintf(fp1, "\t%s\t%s\t%s\n", label, opcode, operand);

        // write header record with label, starting address and final address
        fprintf(fp4, "H^%s^00%s^00%d\n", label, operand, finaladdr);

        // read next input line from intermediate file
        fscanf(fp3, "%d%s%s%s", &address, label, opcode, operand);

        // start the first text record
        // calculate difference from address before the END and current line ( starting address )
        start = address;
        diff = prevaddr - start;
        fprintf(fp4, "T^00%d^%d", address, diff);

    }

    // iterate while not end
    while (strcmp(opcode, "END") != 0)
    {

        // if byte then find corresponding ASCII of operands
        if (strcmp(opcode, "BYTE") == 0)
        {
            // write to output file
            fprintf(fp1, "%d\t%s\t%s\t%s\t", address, label, opcode, operand);

            char buffer[10];
            len = strlen(operand);
            fprintf(fp4, "^");

            // convert whole string to ASCII
            for (i = 2; i < len - 1; i++)
            {
                // convert each character of operand to ASCII
                itoa(operand[i], buffer, 16);

                // write the ASCII to output file and object code file
                fprintf(fp1, "%s", buffer);
                fprintf(fp4, "%s", buffer);
            }

            // goto new line in the output file
            fprintf(fp1, "\n");
        }

        // if word then just convert operands to decimal 
        else if (strcmp(opcode, "WORD") == 0)
        {
            char buffer[10];

            // convert operand from hex to decimal 
            itoa(atoi(operand), buffer, 10);

            // write to output file and object code file
            fprintf(fp1, "%d\t%s\t%s\t%s\t00000%s\n", address, label, opcode, operand, buffer);
            fprintf(fp4, "^00000%s", buffer);
        }

        // if RESB or RESW do not write to object file, directly write it to output file
        else if ((strcmp(opcode, "RESB") == 0) || (strcmp(opcode, "RESW") == 0))
        {
            fprintf(fp1, "%d\t%s\t%s\t%s\n", address, label, opcode, operand);
        }

        else
        {   
            // traverse the optable
            while (strcmp(opcode, mnemonic[j]) != 0) j++;

            // if operand is copy just write it to output file (along with mneumonic's opcode)
            // no need to write to the object file
            if (strcmp(operand, "COPY") == 0)
            {
                fprintf(fp1, "%d\t%s\t%s\t%s\t%s0000\n", address, label, opcode, operand, code[j]);
            }

            // search the symbol table and write opcode with address to where symbol is directed
            else
            {

                // search through the symbol table for symbol and read corresponding address
                int symboladdr;
                rewind(fp2);
                fscanf(fp2, "%s%d", symbol, &symboladdr);
                while (strcmp(operand, symbol) != 0) fscanf(fp2, "%s%d", symbol, &symboladdr);

                // write to the output file and the object code file
                fprintf(fp1, "%d\t%s\t%s\t%s\t%s%d\n", address, label, opcode, operand, code[j], symboladdr);
                fprintf(fp4, "^%s%d", code[j], symboladdr);

            }

        }

        // read the next line from intermediate file ( END line )
        fscanf(fp3, "%d%s%s%s", &address, label, opcode, operand);
    }

    // write the end line tom output file and write the end record
    fprintf(fp1, "%d\t%s\t%s\t%s\n", address, label, opcode, operand);
    fprintf(fp4, "\nE^00%d", start);

    // close all the files
    fclose(fp4);
    fclose(fp3);
    fclose(fp2);
    fclose(fp1);

    // display all the files
    display("intermediate.txt");
    display("output.txt");
    display("objcode.txt");

    return 0;
}