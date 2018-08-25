global	readlink:function
	section	.text

readlink:
	mov	rax, 89
	syscall
	ret