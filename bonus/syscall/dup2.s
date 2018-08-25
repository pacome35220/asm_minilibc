global	dup2:function
	section	.text

dup2:
	mov	rax, 33
	syscall
	ret