global	rt_sigprocmask:function
	section	.text

rt_sigprocmask:
	mov	rax, 14
	syscall
	ret