global	getsockname:function
	section	.text

getsockname:
	mov	rax, 51
	syscall
	ret