global	lsetxattr:function
	section	.text

lsetxattr:
	mov	rax, 189
	syscall
	ret