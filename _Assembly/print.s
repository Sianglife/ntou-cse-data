.intel_syntax noprefix
.global main
.extern printf

.data
fmt:
    .string "%d\n"

.text
main:    
    mov rax, 3
    mov rbx, 7
    add rax, rbx

    lea rdi, [rip + fmt]
    mov rsi, rax
    
    sub rsp, 40
    call printf
    add rsp, 40

    xor rax, rax
    ret
    