
section .text
    global main
    extern printf

main:


    ;printf example
        ;FUNCIONA CON MAIN
        mov rdi, str
        mov rax, 1
        push rdi
        call printf
        pop rdi

    mov rax, 10
    mov [num1], rax
    mov rdi, num1
        mov rax, 1
        push rdi
        ;call printf
        pop rdi

    ;write 'Test example'  
   ; mov edx, 1
   ; mov eax, 394231097
   ; mov [num2], eax
   ; mov eax, [num2]
   ; mov eax, '102'
    ;mov [result], [num1]
   ; mov [num1], eax
   ; mov ecx, eax                 ;Message to write
    ;mov ecx, '102'                 ;Message to write
   ; mov ebx, 1                      ;file descriptor (stdout)
   ; mov eax, 4                      ;System call (sys_write)
   ; int 80h                         ;Call Kernel         


    ;write new message    
    ;mov edx, 4                     ;Message length 
    ;mov [printf_MSG], dword '1234'   ;New message
    ;mov ecx, printf_MSG             ;Message to write
    ;mov ebx, 1                      ;file descriptor (stdout)
    ;mov eax, 4                      ;System call (sys_write)
   ; int 80h                         ;Call Kernel   

   



    jmp exit

exit:
    ; End the program
    mov eax, 1
    mov ebx, 0
    int 80h

section .data

    ; Messages
    printf_MSG        db      10,'Test example',10,0   ;String
    str:             db "test int %d test char %c test string %s", 0Ah, 0
    ex        db      "Hola"   ;String
    fmt:    db "a=%d, eax=%d", 10, 0 ; The printf format, "\n",'0'

    formatINT  db  '%10d', 0xa, 0

section .bss

    ; Spaces reserved for storing the values ​​provided by the user.

    opc         resb    2
    num1        resb    2
    num2        resb    2
    result      resb    2