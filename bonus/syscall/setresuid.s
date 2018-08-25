global	setresuid:function
	section	.text

setresuid:
	mov	rax, 117
	syscall
	ret