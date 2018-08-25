global	sched_get_priority_min:function
	section	.text

sched_get_priority_min:
	mov	rax, 147
	syscall
	ret