global	epoll_ctl_old:function
	section	.text

epoll_ctl_old:
	mov	rax, 214
	syscall
	ret