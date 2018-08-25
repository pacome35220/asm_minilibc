global	mount:function
	section	.text

mount:
	mov	rax, 165
	syscall
	ret