global	getsid:function
	section	.text

getsid:
	mov	rax, 124
	syscall
	ret