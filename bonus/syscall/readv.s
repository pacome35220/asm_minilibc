global	readv:function
	section	.text

readv:
	mov	rax, 19
	syscall
	ret