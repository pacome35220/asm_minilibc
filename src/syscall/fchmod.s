global	fchmod:function
	section	.text

fchmod:
	mov	rax, 91
	syscall
	ret