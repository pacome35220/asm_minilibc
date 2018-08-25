global	mq_open:function
	section	.text

mq_open:
	mov	rax, 240
	syscall
	ret