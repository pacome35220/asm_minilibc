global	fstat:function
	section	.text

fstat:
	mov	rax, 5
	syscall
	ret