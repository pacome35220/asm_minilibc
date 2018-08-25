global	futex:function
	section	.text

futex:
	mov	rax, 202
	syscall
	ret