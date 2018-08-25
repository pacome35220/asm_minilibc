global	getsockopt:function
	section	.text

getsockopt:
	mov	rax, 55
	syscall
	ret