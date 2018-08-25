global	io_cancel:function
	section	.text

io_cancel:
	mov	rax, 210
	syscall
	ret