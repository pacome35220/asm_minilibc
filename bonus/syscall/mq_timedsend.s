global	mq_timedsend:function
	section	.text

mq_timedsend:
	mov	rax, 242
	syscall
	ret