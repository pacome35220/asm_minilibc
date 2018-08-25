global	removexattr:function
	section	.text

removexattr:
	mov	rax, 197
	syscall
	ret