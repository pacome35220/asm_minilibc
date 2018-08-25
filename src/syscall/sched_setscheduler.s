global	sched_setscheduler:function
	section	.text

sched_setscheduler:
	mov	rax, 144
	syscall
	ret