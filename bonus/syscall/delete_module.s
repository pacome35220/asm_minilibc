global	delete_module:function
	section	.text

delete_module:
	mov	rax, 176
	syscall
	ret