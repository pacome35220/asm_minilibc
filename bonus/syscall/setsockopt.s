global	setsockopt:function
	section	.text

setsockopt:
	mov	rax, 54
	syscall
	ret