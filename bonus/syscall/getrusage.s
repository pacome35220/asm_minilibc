global	getrusage:function
	section	.text

getrusage:
	mov	rax, 98
	syscall
	ret