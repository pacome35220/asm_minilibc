global	fchdir:function
	section	.text

fchdir:
	mov	rax, 81
	syscall
	ret