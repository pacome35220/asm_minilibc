global	ioprio_get:function
	section	.text

ioprio_get:
	mov	rax, 252
	syscall
	ret