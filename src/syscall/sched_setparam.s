global	sched_setparam:function
	section	.text

sched_setparam:
	mov	rax, 142
	syscall
	ret