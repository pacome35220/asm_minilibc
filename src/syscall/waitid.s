global	waitid:function
	section	.text

waitid:
	mov	rax, 247
	syscall
	ret