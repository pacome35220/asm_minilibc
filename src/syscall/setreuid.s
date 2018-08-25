global	setreuid:function
	section	.text

setreuid:
	mov	rax, 113
	syscall
	ret