global	mq_unlink:function
	section	.text

mq_unlink:
	mov	rax, 241
	syscall
	ret