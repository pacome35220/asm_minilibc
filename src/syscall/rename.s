global	rename:function
	section	.text

rename:
	mov	rax, 82
	syscall
	ret