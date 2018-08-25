global	getpid:function
	section	.text

getpid:
	mov	rax, 39
	syscall
	ret