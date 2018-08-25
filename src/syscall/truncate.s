global	truncate:function
	section	.text

truncate:
	mov	rax, 76
	syscall
	ret