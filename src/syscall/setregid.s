global	setregid:function
	section	.text

setregid:
	mov	rax, 114
	syscall
	ret