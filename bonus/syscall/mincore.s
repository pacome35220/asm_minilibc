global	mincore:function
	section	.text

mincore:
	mov	rax, 27
	syscall
	ret