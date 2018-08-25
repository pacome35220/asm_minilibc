global	setfsgid:function
	section	.text

setfsgid:
	mov	rax, 123
	syscall
	ret