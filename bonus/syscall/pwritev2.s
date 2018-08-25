global	pwritev2:function
	section	.text

pwritev2:
	mov	rax, 328
	syscall
	ret