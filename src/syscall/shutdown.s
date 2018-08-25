global	shutdown:function
	section	.text

shutdown:
	mov	rax, 48
	syscall
	ret