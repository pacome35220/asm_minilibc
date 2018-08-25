global	eventfd2:function
	section	.text

eventfd2:
	mov	rax, 290
	syscall
	ret