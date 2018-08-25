global	iopl:function
	section	.text

iopl:
	mov	rax, 172
	syscall
	ret