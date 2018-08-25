global	rt_sigreturn:function
	section	.text

rt_sigreturn:
	mov	rax, 15
	syscall
	ret