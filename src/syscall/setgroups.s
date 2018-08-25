global	setgroups:function
	section	.text

setgroups:
	mov	rax, 116
	syscall
	ret