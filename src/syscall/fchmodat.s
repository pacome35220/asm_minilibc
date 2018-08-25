global	fchmodat:function
	section	.text

fchmodat:
	mov	rax, 268
	syscall
	ret