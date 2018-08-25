global	execveat:function
	section	.text

execveat:
	mov	rax, 322
	syscall
	ret