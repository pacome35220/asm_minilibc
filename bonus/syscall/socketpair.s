global	socketpair:function
	section	.text

socketpair:
	mov	rax, 53
	syscall
	ret