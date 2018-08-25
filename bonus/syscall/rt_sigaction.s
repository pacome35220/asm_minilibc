global	rt_sigaction:function
	section	.text

rt_sigaction:
	mov	rax, 13
	syscall
	ret