global	ftruncate:function
	section	.text

ftruncate:
	mov	rax, 77
	syscall
	ret