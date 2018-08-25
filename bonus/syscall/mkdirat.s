global	mkdirat:function
	section	.text

mkdirat:
	mov	rax, 258
	syscall
	ret