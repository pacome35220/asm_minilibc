global	mlock2:function
	section	.text

mlock2:
	mov	rax, 325
	syscall
	ret