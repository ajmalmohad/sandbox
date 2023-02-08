        MOV CX, 00
        MOV AX, 8086
        MOV BX, 8080
        SUB AX, BX
        JNB 404E
        INC CX
404E    MOV [5000], AX
        MOV [5002], CX
        HLT