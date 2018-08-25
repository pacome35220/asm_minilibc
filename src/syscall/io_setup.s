global	io_setup:function
	section	.text

io_setup:
	mov	rax, 206
	syscall
	ret