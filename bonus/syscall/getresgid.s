global	getresgid:function
	section	.text

getresgid:
	mov	rax, 120
	syscall
	ret