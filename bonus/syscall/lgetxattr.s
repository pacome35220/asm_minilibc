global	lgetxattr:function
	section	.text

lgetxattr:
	mov	rax, 192
	syscall
	ret