global	setpriority:function
	section	.text

setpriority:
	mov	rax, 141
	syscall
	ret