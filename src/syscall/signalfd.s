global	signalfd:function
	section	.text

signalfd:
	mov	rax, 282
	syscall
	ret