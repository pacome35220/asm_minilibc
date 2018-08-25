global	epoll_wait:function
	section	.text

epoll_wait:
	mov	rax, 232
	syscall
	ret