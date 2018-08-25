global	msgctl:function
	section	.text

msgctl:
	mov	rax, 71
	syscall
	ret