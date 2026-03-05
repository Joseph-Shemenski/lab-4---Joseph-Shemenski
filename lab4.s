.section .text
.globl sum_up
sum_up:
    movl $0, %eax
    mov $0, %rdx # hold iterator

repeat:
    
    add (%rdi,%rdx,4), %eax # adds the integer at the index to eax
    inc %rdx                # increments counter by 1
    cmp %rsi, %rdx          # compares counter to max loop
    jne repeat              # repeats if the counter is not equal to max loop
    ret                     # if they are equal then it returns 
  

.section .note.GNU-stack,"",@progbits
