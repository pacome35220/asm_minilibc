global	epoll_wait_old:function
	section	.text

epoll_wait_old:
	mov	rax, 215
	syscall
	ret