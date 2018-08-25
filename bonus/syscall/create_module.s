global	create_module:function
	section	.text

create_module:
	mov	rax, 174
	syscall
	ret