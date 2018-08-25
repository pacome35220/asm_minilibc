global	epoll_pwait:function
	section	.text

epoll_pwait:
	mov	rax, 281
	syscall
	ret