global	sched_setattr:function
	section	.text

sched_setattr:
	mov	rax, 314
	syscall
	ret