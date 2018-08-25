global	mq_timedreceive:function
	section	.text

mq_timedreceive:
	mov	rax, 243
	syscall
	ret