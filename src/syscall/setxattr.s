global	setxattr:function
	section	.text

setxattr:
	mov	rax, 188
	syscall
	ret