        MOV AX, 8080
        MOV BX, 6060
        DIV BX
        MOV [5000], AX
        MOV [5002], DX
        HLT