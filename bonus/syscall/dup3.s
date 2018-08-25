global	dup3:function
	section	.text

dup3:
	mov	rax, 292
	syscall
	ret