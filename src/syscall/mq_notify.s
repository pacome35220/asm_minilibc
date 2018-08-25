global	mq_notify:function
	section	.text

mq_notify:
	mov	rax, 244
	syscall
	ret