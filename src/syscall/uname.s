global	uname:function
	section	.text

uname:
	mov	rax, 63
	syscall
	ret