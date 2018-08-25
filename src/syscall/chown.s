global	chown:function
	section	.text

chown:
	mov	rax, 92
	syscall
	ret