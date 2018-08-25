global	epoll_ctl:function
	section	.text

epoll_ctl:
	mov	rax, 233
	syscall
	ret