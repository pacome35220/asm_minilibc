global	symlinkat:function
	section	.text

symlinkat:
	mov	rax, 266
	syscall
	ret