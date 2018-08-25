global	rt_sigsuspend:function
	section	.text

rt_sigsuspend:
	mov	rax, 130
	syscall
	ret