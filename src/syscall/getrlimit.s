global	getrlimit:function
	section	.text

getrlimit:
	mov	rax, 97
	syscall
	ret