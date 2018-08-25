global	sync:function
	section	.text

sync:
	mov	rax, 162
	syscall
	ret