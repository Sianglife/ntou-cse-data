.intel_syntax noprefix
.global main
.extern printf

.data
fmt:
    .string "%d\n"

.text
main:
    sub rsp, 40
    mov rcx, 0          # Initialize counter to 0
    lea rdi, [rip + fmt] # Set printf format

loop_add:
    add rcx, 1
    mov rsi, rcx

    call printf
    add rsp, 40

    cmp rcx, 10
    jne loop_add

end:
    xor rax, rax
    ret


    