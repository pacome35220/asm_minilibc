global	timerfd_settime:function
	section	.text

timerfd_settime:
	mov	rax, 286
	syscall
	ret