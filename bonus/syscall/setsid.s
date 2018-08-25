global	setsid:function
	section	.text

setsid:
	mov	rax, 112
	syscall
	ret