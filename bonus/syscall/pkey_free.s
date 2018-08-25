global	pkey_free:function
	section	.text

pkey_free:
	mov	rax, 331
	syscall
	ret