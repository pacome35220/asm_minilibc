global	getcwd:function
	section	.text

getcwd:
	mov	rax, 79
	syscall
	ret