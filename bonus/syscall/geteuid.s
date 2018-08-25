global	geteuid:function
	section	.text

geteuid:
	mov	rax, 107
	syscall
	ret