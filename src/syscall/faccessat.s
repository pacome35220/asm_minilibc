global	faccessat:function
	section	.text

faccessat:
	mov	rax, 269
	syscall
	ret