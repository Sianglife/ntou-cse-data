.intel_syntax noprefix
.global main
.extern printf

.data
fmt:
    .string "%d\n"

.text

print:
    sub rsp, 8
    call printf
    add rsp, 8  
    call return
    
    
    
main:
    mov rax, 7
    mov rbx, 3
    add rax, rbx

    lea rdi, [rip + fmt]
    mov rsi, rax

    sub rsp, 40
    call print

return:
    xor rax, rax
    ret

