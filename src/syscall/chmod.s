global	chmod:function
	section	.text

chmod:
	mov	rax, 90
	syscall
	ret