global	flistxattr:function
	section	.text

flistxattr:
	mov	rax, 196
	syscall
	ret