global	sched_yield:function
	section	.text

sched_yield:
	mov	rax, 24
	syscall
	ret