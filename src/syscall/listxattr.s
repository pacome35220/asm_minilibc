global	listxattr:function
	section	.text

listxattr:
	mov	rax, 194
	syscall
	ret