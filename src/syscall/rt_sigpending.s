global	rt_sigpending:function
	section	.text

rt_sigpending:
	mov	rax, 127
	syscall
	ret