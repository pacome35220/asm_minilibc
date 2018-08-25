global	mknodat:function
	section	.text

mknodat:
	mov	rax, 259
	syscall
	ret