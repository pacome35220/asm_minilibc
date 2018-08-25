global	unlink:function
	section	.text

unlink:
	mov	rax, 87
	syscall
	ret