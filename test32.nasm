extern printf

section .text
    ;global _start
    global main

;_start:
main:


    ;printf example


    mov eax, 10000
    mov ebx, 10000
    cmp eax, ebx
  ;JUMP SIZES $+Size
  ;jmp $+7    
  ;mov eax, 2000  ;size of 5
  ;
  ;inc eax     ;Size of 1
  ;inc eax
  ;jmp $+4
  ;jmp exit     ;Size of 2
  ;jmp $+4
  ;jmp exit     ;Size of 2

    
;Implementacion de if con '||'
    ;Contenido
    mov eax, 12
    mov ebx, 10
    ;Comparacion
    cmp eax, ebx 

    ;If 
    je IFOR       ;Condicion aceptada 

    ;Contenido
    mov eax, 10
    mov ebx, 10
    ;Comparacion
    cmp eax, ebx 

    ;|| If
    je IFOR       ;Condicion aceptada 

    ;Contenido
    mov eax, 11
    mov ebx, 10
    ;Comparacion
    cmp eax, ebx 

    ;|| Ultimo If
    je IFOR 

    ;Ir a else     
    jmp  exit 

;If Label
IFOR:
    mov eax, 109
    mov [num1], eax
    mov eax, [num1]
    push eax                ; eax = 1
    push fmt
    call printf             
    add esp, 8 












    ;Implementacion de if con '&&'
    ;Contenido
    mov eax, 10
    mov ebx, 10
    ;Comparacion
    cmp eax, ebx 

    ;If
    je $+4       ;Saltar el else 

    ;ir a Else       
    jmp  exit     
    
    ;Contenido
    mov eax, 10
    mov ebx, 10
    ;Comparacion
    cmp eax, ebx 

    ;&& If
    je $+4       ;Saltar el else   

    ;ir a else      
    jmp  exit 

    ;Contenido
    mov eax, 10
    mov ebx, 10
    ;Comparacion
    cmp eax, ebx 

    ;&& Ultimo If
    je IFAND 

    ;Ultimo ir a else      
    jmp  exit 

;If Label
IFAND:
    mov eax, 109
    mov [num1], eax
    mov eax, [num1]
    push eax                ; eax = 1
    push fmt
    call printf             
    add esp, 8  




    ;Print number 109 with printf
    mov eax, 109
    mov [num1], eax
    mov eax, [num1]
    push eax                ; eax = 1
    push fmt                ; fmt = "content in eax=%d",0xa,0
    call printf             
    add esp, 8 



    ;write new message without printf

    MOV edx, 10                         ;Message length 
  ;  mov [printf_MSG], dword 'Hola'      ;New message
  ;  mov [printf_MSG+4], dword 'mund'    ;New message
  ;  mov [printf_MSG+8], dword 'o'       ;New message
  ;  mov [printf_MSG+9], dword 10        ;New message
  ;  mov ecx, printf_MSG                 ;Message to write
    ;mov ebx, 1                          ;file descriptor (stdout)
    ;mov eax, 4                          ;System call (sys_write)
    ;int 80h                             ;Call Kernel  
    push printf_MSG;
    call printf
    add esp, 4

    push hola
    push str
    call printf
    add esp, 8




    ;mov eax, [num2]    ; put a from store into register
    ;add eax, 2      ; a+2
    ;push    eax     ; value of a+2
    ;push    dword [num2]   ; value of variable a
    ;push    dword fmt   ; address of ctrl string
    ;call    _printf      ; Call C function
    ;add     esp, 12     ; pop stack 3 push times 4 bytes

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
    ;mov eax, 10
    ;mov [num1], eax
    ;mov [printf_MSG], dword num1   ;New message
    ;mov ecx, printf_MSG             ;Message to write
    ;mov ebx, 1                      ;file descriptor (stdout)
    ;mov eax, 4                      ;System call (sys_write)
    ;int 80h                         ;Call Kernel   

   



    jmp exit

exit:
    ; End the program
    mov eax, 1
    mov ebx, 0
    int 80h

section .data

    ; Messages
    printf_MSG        db      10,'Test example',10,0   ;String
    ex        db      "Hola"   ;String

    fmt:              db      "content in eax=%d",0xa,0
    str:              db      'The string is: %s',10,0
    hola:             db      'Hola Mundo!',10,0

    ;formatINT  db  '%10d', 0xa, 0

section .bss

    ; Spaces reserved for storing the values ​​provided by the user.

    opc         resb    2
    num1        resb    2
    num2        resb    2
    result      resb    2