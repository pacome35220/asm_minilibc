global	lstat:function
	section	.text

lstat:
	mov	rax, 6
	syscall
	ret