global	ioprio_set:function
	section	.text

ioprio_set:
	mov	rax, 251
	syscall
	ret