global	io_destroy:function
	section	.text

io_destroy:
	mov	rax, 207
	syscall
	ret