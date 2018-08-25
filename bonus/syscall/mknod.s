global	mknod:function
	section	.text

mknod:
	mov	rax, 133
	syscall
	ret