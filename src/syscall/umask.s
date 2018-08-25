global	umask:function
	section	.text

umask:
	mov	rax, 95
	syscall
	ret