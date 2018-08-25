global	eventfd:function
	section	.text

eventfd:
	mov	rax, 284
	syscall
	ret