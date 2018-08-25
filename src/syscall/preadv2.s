global	preadv2:function
	section	.text

preadv2:
	mov	rax, 327
	syscall
	ret