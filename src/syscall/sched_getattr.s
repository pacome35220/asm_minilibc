global	sched_getattr:function
	section	.text

sched_getattr:
	mov	rax, 315
	syscall
	ret