global	getppid:function
	section	.text

getppid:
	mov	rax, 110
	syscall
	ret