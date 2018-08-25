global	sched_getaffinity:function
	section	.text

sched_getaffinity:
	mov	rax, 204
	syscall
	ret