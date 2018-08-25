global	setgid:function
	section	.text

setgid:
	mov	rax, 106
	syscall
	ret