global	io_getevents:function
	section	.text

io_getevents:
	mov	rax, 208
	syscall
	ret