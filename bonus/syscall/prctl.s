global	prctl:function
	section	.text

prctl:
	mov	rax, 157
	syscall
	ret