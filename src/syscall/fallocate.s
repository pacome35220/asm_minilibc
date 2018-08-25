global	fallocate:function
	section	.text

fallocate:
	mov	rax, 285
	syscall
	ret