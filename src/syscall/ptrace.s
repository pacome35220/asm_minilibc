global	ptrace:function
	section	.text

ptrace:
	mov	rax, 101
	syscall
	ret