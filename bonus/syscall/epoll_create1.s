global	epoll_create1:function
	section	.text

epoll_create1:
	mov	rax, 291
	syscall
	ret