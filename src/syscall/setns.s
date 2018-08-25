global	setns:function
	section	.text

setns:
	mov	rax, 308
	syscall
	ret