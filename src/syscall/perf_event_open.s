global	perf_event_open:function
	section	.text

perf_event_open:
	mov	rax, 298
	syscall
	ret