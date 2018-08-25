global	ustat:function
	section	.text

ustat:
	mov	rax, 136
	syscall
	ret