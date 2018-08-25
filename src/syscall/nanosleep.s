global	nanosleep:function
	section	.text

nanosleep:
	mov	rax, 35
	syscall
	ret