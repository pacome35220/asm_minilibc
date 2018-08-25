global	timerfd_gettime:function
	section	.text

timerfd_gettime:
	mov	rax, 287
	syscall
	ret