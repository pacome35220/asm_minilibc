global	sched_getparam:function
	section	.text

sched_getparam:
	mov	rax, 143
	syscall
	ret