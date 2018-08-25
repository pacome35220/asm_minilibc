global	llistxattr:function
	section	.text

llistxattr:
	mov	rax, 195
	syscall
	ret