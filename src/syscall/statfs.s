global	statfs:function
	section	.text

statfs:
	mov	rax, 137
	syscall
	ret