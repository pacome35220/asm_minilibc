global	lremovexattr:function
	section	.text

lremovexattr:
	mov	rax, 198
	syscall
	ret