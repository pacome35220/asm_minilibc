global	fork:function
	section	.text

fork:
	mov	rax, 57
	syscall
	ret