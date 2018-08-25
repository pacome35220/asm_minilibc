global	sched_rr_get_interval:function
	section	.text

sched_rr_get_interval:
	mov	rax, 148
	syscall
	ret