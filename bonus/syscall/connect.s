global	connect:function
	section	.text

connect:
	mov	rax, 42
	syscall
	ret