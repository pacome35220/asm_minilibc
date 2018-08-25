global	msgget:function
	section	.text

msgget:
	mov	rax, 68
	syscall
	ret