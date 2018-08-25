global	fchown:function
	section	.text

fchown:
	mov	rax, 93
	syscall
	ret