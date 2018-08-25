global	capget:function
	section	.text

capget:
	mov	rax, 125
	syscall
	ret