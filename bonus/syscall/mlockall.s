global	mlockall:function
	section	.text

mlockall:
	mov	rax, 151
	syscall
	ret