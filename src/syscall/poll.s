global	poll:function
	section	.text

poll:
	mov	rax, 7
	syscall
	ret