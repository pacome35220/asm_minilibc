global	security:function
	section	.text

security:
	mov	rax, 185
	syscall
	ret