global	unlinkat:function
	section	.text

unlinkat:
	mov	rax, 263
	syscall
	ret