global	fsetxattr:function
	section	.text

fsetxattr:
	mov	rax, 190
	syscall
	ret