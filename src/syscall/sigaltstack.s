global	sigaltstack:function
	section	.text

sigaltstack:
	mov	rax, 131
	syscall
	ret