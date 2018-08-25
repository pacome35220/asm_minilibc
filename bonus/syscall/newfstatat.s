global	newfstatat:function
	section	.text

newfstatat:
	mov	rax, 262
	syscall
	ret