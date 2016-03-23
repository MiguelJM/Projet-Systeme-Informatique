section .text

    global _start

_start:
    
    ;write 'Test example'  
    mov edx, 93                     ;Message length 
    mov ecx, printf_MSG             ;Message to write
    mov ebx, 1                      ;file descriptor (stdout)
    mov eax, 4                      ;System call (sys_write)
    int 80h                         ;Call Kernel          

    ;write new message    
    ;mov edx, 4                     ;Message length 
    ;mov [printf_MSG], dword '1234'   ;New message
    ;mov ecx, printf_MSG             ;Message to write
    ;mov ebx, 1                      ;file descriptor (stdout)
    ;mov eax, 4                      ;System call (sys_write)
   ; int 80h                         ;Call Kernel   

    ;write new message
    mov eax, 10
    mov ebx, 10
    cmp eax, ebx                    ;Message length 
    je  iflbl1; 
    jmp ifNOTlbl1; 
iflbl1:
    MOV edx, 9   
    mov [printf_MSG], dword '1234'   ;New message
    mov [printf_MSG+4], dword '5678'   ;New message
    mov [printf_MSG+8], dword 10  ;New message
    mov ecx, printf_MSG             ;Message to write
    mov ebx, 1                      ;file descriptor (stdout)
    mov eax, 4                      ;System call (sys_write)
    int 80h                         ;Call Kernel  

ifNOTlbl1:    
    MOV edx, 16                     ;Message length 
    mov [printf_MSG], dword 'hola'   ;New message
    mov [printf_MSG+4], dword 'Quer'   ;New message
    mov [printf_MSG+8], dword 'idoM'   ;New message
    mov [printf_MSG+12], dword 'undo'   ;New message
    mov ecx, printf_MSG             ;Message to write
    mov ebx, 1                      ;file descriptor (stdout)
    mov eax, 4                      ;System call (sys_write)
    int 80h                         ;Call Kernel  



    jmp exit

exit:
    ; End the program
    mov eax, 1
    mov ebx, 0
    int 80h

section .data

    ; Messages
    printf_MSG        db      10,'Test example',10,0   ;String

section .bss

    ; Spaces reserved for storing the values ​​provided by the user.

    opc         resb    2
    num1        resb    2
    num2        resb    2
    result      resb    2