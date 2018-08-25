global	getdents:function
	section	.text

getdents:
	mov	rax, 78
	syscall
	ret