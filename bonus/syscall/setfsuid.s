global	setfsuid:function
	section	.text

setfsuid:
	mov	rax, 122
	syscall
	ret