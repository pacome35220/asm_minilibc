global	io_submit:function
	section	.text

io_submit:
	mov	rax, 209
	syscall
	ret