global	preadv:function
	section	.text

preadv:
	mov	rax, 295
	syscall
	ret