global	pwrite64:function
	section	.text

pwrite64:
	mov	rax, 18
	syscall
	ret