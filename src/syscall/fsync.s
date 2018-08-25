global	fsync:function
	section	.text

fsync:
	mov	rax, 74
	syscall
	ret