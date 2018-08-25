global	init_module:function
	section	.text

init_module:
	mov	rax, 175
	syscall
	ret