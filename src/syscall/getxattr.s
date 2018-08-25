global	getxattr:function
	section	.text

getxattr:
	mov	rax, 191
	syscall
	ret