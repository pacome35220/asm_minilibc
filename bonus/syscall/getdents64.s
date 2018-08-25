global	getdents64:function
	section	.text

getdents64:
	mov	rax, 217
	syscall
	ret