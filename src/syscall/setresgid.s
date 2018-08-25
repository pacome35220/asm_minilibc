global	setresgid:function
	section	.text

setresgid:
	mov	rax, 119
	syscall
	ret