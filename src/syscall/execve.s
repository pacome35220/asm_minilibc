global	execve:function
	section	.text

execve:
	mov	rax, 59
	syscall
	ret