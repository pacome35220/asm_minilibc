global	writev:function
	section	.text

writev:
	mov	rax, 20
	syscall
	ret