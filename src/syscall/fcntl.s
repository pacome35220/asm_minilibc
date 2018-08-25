global	fcntl:function
	section	.text

fcntl:
	mov	rax, 72
	syscall
	ret