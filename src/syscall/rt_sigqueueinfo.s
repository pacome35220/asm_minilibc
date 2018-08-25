global	rt_sigqueueinfo:function
	section	.text

rt_sigqueueinfo:
	mov	rax, 129
	syscall
	ret