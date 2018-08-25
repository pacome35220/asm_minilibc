global	query_module:function
	section	.text

query_module:
	mov	rax, 178
	syscall
	ret