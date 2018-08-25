global	lchown:function
	section	.text

lchown:
	mov	rax, 94
	syscall
	ret