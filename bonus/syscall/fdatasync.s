global	fdatasync:function
	section	.text

fdatasync:
	mov	rax, 75
	syscall
	ret