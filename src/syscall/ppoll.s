global	ppoll:function
	section	.text

ppoll:
	mov	rax, 271
	syscall
	ret