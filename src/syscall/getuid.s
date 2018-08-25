global	getuid:function
	section	.text

getuid:
	mov	rax, 102
	syscall
	ret