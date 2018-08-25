global	futimesat:function
	section	.text

futimesat:
	mov	rax, 261
	syscall
	ret