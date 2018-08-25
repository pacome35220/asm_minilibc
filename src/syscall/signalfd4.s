global	signalfd4:function
	section	.text

signalfd4:
	mov	rax, 289
	syscall
	ret