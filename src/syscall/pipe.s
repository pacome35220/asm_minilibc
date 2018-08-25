global	pipe:function
	section	.text

pipe:
	mov	rax, 22
	syscall
	ret