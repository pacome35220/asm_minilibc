global	rt_sigtimedwait:function
	section	.text

rt_sigtimedwait:
	mov	rax, 128
	syscall
	ret