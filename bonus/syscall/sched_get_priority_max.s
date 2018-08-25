global	sched_get_priority_max:function
	section	.text

sched_get_priority_max:
	mov	rax, 146
	syscall
	ret