global	setuid:function
	section	.text

setuid:
	mov	rax, 105
	syscall
	ret