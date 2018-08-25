global	sched_getscheduler:function
	section	.text

sched_getscheduler:
	mov	rax, 145
	syscall
	ret