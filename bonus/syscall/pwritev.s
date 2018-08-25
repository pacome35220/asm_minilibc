global	pwritev:function
	section	.text

pwritev:
	mov	rax, 296
	syscall
	ret