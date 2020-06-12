    section     .text
    global      my_strlen

my_strlen:
        push    rdi
	sub	rcx, rcx
	mov	rdi, [esp+8]
	not	rcx
	sub	al, al
	cld
repne	scasb
	not	rcx
	pop	rdi
	lea	rax, [rcx-1]
	ret
