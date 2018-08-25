global	getresuid:function
	section	.text

getresuid:
	mov	rax, 118
	syscall
	ret