global	rmdir:function
	section	.text

rmdir:
	mov	rax, 84
	syscall
	ret