global	sched_setaffinity:function
	section	.text

sched_setaffinity:
	mov	rax, 203
	syscall
	ret