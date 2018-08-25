global	mq_getsetattr:function
	section	.text

mq_getsetattr:
	mov	rax, 245
	syscall
	ret