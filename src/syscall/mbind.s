global	mbind:function
	section	.text

mbind:
	mov	rax, 237
	syscall
	ret