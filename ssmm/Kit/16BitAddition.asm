        MOV CX, 00
        MOV AX, 8080
        MOV BX, 8086
        ADD AX, BX
        JNC 404E
        INC CX
404E    MOV [5000], AX      
        MOV [5002], CX
        HLT