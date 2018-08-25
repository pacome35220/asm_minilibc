global	pkey_alloc:function
	section	.text

pkey_alloc:
	mov	rax, 330
	syscall
	ret