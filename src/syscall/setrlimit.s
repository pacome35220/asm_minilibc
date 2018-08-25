global	setrlimit:function
	section	.text

setrlimit:
	mov	rax, 160
	syscall
	ret