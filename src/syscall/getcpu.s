global	getcpu:function
	section	.text

getcpu:
	mov	rax, 309
	syscall
	ret