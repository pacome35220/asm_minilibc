global	ioperm:function
	section	.text

ioperm:
	mov	rax, 173
	syscall
	ret