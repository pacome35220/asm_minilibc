global	ioctl:function
	section	.text

ioctl:
	mov	rax, 16
	syscall
	ret