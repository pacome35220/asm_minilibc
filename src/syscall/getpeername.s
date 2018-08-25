global	getpeername:function
	section	.text

getpeername:
	mov	rax, 52
	syscall
	ret