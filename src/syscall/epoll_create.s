global	epoll_create:function
	section	.text

epoll_create:
	mov	rax, 213
	syscall
	ret