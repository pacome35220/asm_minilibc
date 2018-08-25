global	pread64:function
	section	.text

pread64:
	mov	rax, 17
	syscall
	ret