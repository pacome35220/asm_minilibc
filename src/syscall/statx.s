global	statx:function
	section	.text

statx:
	mov	rax, 332
	syscall
	ret