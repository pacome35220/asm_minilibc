global	membarrier:function
	section	.text

membarrier:
	mov	rax, 324
	syscall
	ret