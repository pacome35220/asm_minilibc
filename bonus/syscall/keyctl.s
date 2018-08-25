global	keyctl:function
	section	.text

keyctl:
	mov	rax, 250
	syscall
	ret