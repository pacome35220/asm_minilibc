global	mremap:function
	section	.text

mremap:
	mov	rax, 25
	syscall
	ret