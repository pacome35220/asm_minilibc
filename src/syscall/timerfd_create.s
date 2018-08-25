global	timerfd_create:function
	section	.text

timerfd_create:
	mov	rax, 283
	syscall
	ret